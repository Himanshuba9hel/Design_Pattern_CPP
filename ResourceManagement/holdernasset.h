#ifndef HOLDERNASSET_H
#define HOLDERNASSET_H

class Holder;
class Asset;
class Student;
class Pencil;
class HolderNAsset
{
public:
    HolderNAsset();
};

class Holder
{
public:
    virtual Holder* getHolder() = 0;

    virtual void setBorrower(Holder* borrower) = 0;
    virtual Holder* borrowFrom() = 0;

    virtual void setGiver(Holder* giver)  = 0;
    virtual Holder* givenTo()  = 0;


    virtual void giveAsset(Holder* borrower) = 0;
    virtual void takeAsset(Holder* giver, Asset* asset) = 0;
};

class Asset
{
public:
    virtual Holder* getOwner() = 0;
    virtual void setOwner(Holder* owner) = 0;
};

class Student: public Holder
{
protected:
    Student* giver = nullptr, borrower = nullptr;
private:
    Pencil* pencil;
public:
    Student* getHolder() override { return this; }

    void setBorrower(Student* borrower) override { this->borrower = borrower; }
    Student* borrowFrom() override { return giver; }

    void setGiver(Student* giver) override { this->giver = giver; }
    Student* givenTo() override { return giver; }

    void giveAsset(Student* borrower) override;
    void takeAsset(Student* giver, Pencil* asset) override;
};

class Pencil: public Asset
{

};

#endif // HOLDERNASSET_H
