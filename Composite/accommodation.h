#ifndef ACCOMMODATION_H
#define ACCOMMODATION_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <stdexcept>
// ---------------------------------------------------------
// 1. Non-Copyable Entity
// ---------------------------------------------------------
class Entity {
private:
    int id_;
    std::string name_;

public:
    Entity(int id, std::string name);
    ~Entity();

    // Forbid copying so the entity remains a single unique instance
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    // Allow moving
    Entity(Entity&&) noexcept = default;
    Entity& operator=(Entity&&) noexcept = default;

    int getId() const;
    const std::string& getName() const;
};

// ---------------------------------------------------------
// 2. Base Component (Composite Pattern)
// ---------------------------------------------------------
class Accommodation {
protected:
    std::string name_;
    Accommodation* parent_ = nullptr;
    std::vector<std::shared_ptr<Accommodation>> children_;
    std::unordered_map<int, std::unique_ptr<Entity>> occupants_;

    virtual void onEntityEnter(const Entity& entity) const;
    virtual void onEntityExit(const Entity& entity) const;

public:
    explicit Accommodation(std::string name);
    virtual ~Accommodation() = default;

    virtual void addChild(std::shared_ptr<Accommodation> child);

    void enter(std::unique_ptr<Entity> entity);
    std::unique_ptr<Entity> exit(int entityId);
    void transferTo(int entityId, Accommodation& destination);

    // Inspection helpers for verification and testing
    bool hasEntity(int entityId) const;
    const Entity* getEntity(int entityId) const;
    std::size_t getOccupantCount() const;
    const std::string& getName() const;
};

// ---------------------------------------------------------
// 3. Composite Accommodations (Nested Containers)
// ---------------------------------------------------------
class Building : public Accommodation {
public:
    explicit Building(std::string name);
};

class Floor : public Accommodation {
public:
    explicit Floor(int number);
};

// ---------------------------------------------------------
// 4. Leaf Accommodations (Specific Room Types)
// ---------------------------------------------------------
class Office : public Accommodation {
public:
    explicit Office(std::string name);
    void addChild(std::shared_ptr<Accommodation> child) override;

protected:
    void onEntityEnter(const Entity& entity) const override;
};

class Restaurant : public Accommodation {
public:
    explicit Restaurant(std::string name);
    void addChild(std::shared_ptr<Accommodation> child) override;

protected:
    void onEntityEnter(const Entity& entity) const override;
};

class GamePark : public Accommodation {
public:
    explicit GamePark(std::string name);
    void addChild(std::shared_ptr<Accommodation> child) override;

protected:
    void onEntityEnter(const Entity& entity) const override;
};

#endif // ACCOMMODATION_H