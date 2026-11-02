#ifndef HOLDERNASSET_H
#define HOLDERNASSET_H

#include <iostream>

class Asset;

// -------------------------------------------------------------
// Base Holder Interface
// -------------------------------------------------------------
class Holder
{
public:
    virtual ~Holder() = default;

    virtual Holder* getHolder() = 0;

    virtual void setBorrower(Holder* borrower) = 0;
    virtual Holder* getBorrower() const = 0;

    virtual void setGiver(Holder* giver) = 0;
    virtual Holder* getGiver() const = 0;

    virtual void giveAsset(Holder* borrower) = 0;
    virtual void takeAsset(Holder* giver, Asset* asset) = 0;
};

// -------------------------------------------------------------
// Base Asset Interface
// -------------------------------------------------------------
class Asset
{
public:
    virtual ~Asset() = default;

    virtual Holder* getOwner() const = 0;
    virtual void setOwner(Holder* owner) = 0;
};

// -------------------------------------------------------------
// Concrete Asset: Pencil
// -------------------------------------------------------------
class Pencil : public Asset
{
private:
    Holder* owner_ = nullptr;

public:
    Pencil() = default;
    explicit Pencil(Holder* owner) : owner_(owner) {}

    Holder* getOwner() const override { return owner_; }
    void setOwner(Holder* owner) override { owner_ = owner; }
};

// -------------------------------------------------------------
// Concrete Holder: Student
// -------------------------------------------------------------
class Student : public Holder
{
protected:
    Holder* giver_ = nullptr;
    Holder* borrower_ = nullptr;
    Asset* asset_ = nullptr; // Represents the asset currently held (e.g., Pencil)

public:
    Student() = default;
    explicit Student(Asset* asset) : asset_(asset) {
        if (asset_) {
            asset_->setOwner(this);
        }
    }

    Holder* getHolder() override { return this; }

    void setBorrower(Holder* borrower) override { borrower_ = borrower; }
    Holder* getBorrower() const override { return borrower_; }

    void setGiver(Holder* giver) override { giver_ = giver; }
    Holder* getGiver() const override { return giver_; }

    // Transfer asset from this student to the borrower
    void giveAsset(Holder* borrower) override
    {
        if (!asset_ || !borrower) return;

        Holder* nextBorrower = borrower;
        Asset* transferredAsset = asset_;

        // Clear own asset and update relationship
        asset_ = nullptr;
        setBorrower(nextBorrower);

        // Deliver asset to recipient
        nextBorrower->takeAsset(this, transferredAsset);
    }

    // Accept asset from giver
    void takeAsset(Holder* giver, Asset* asset) override
    {
        asset_ = asset;
        setGiver(giver);
        if (asset_) {
            asset_->setOwner(this);
        }
    }

    Asset* currentAsset() const { return asset_; }
};

#endif // HOLDERNASSET_H