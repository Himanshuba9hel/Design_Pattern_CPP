#include "accommodation.h"
#include <iostream>

// ---------------------------------------------------------
// Entity Implementation
// ---------------------------------------------------------
Entity::Entity(int id, std::string name) : id_(id), name_(std::move(name)) {
    std::cout << "[Constructed] Entity '" << name_
              << "' at memory address: " << this << "\n";
}

Entity::~Entity() {
    std::cout << "[Destroyed]   Entity '" << name_
              << "' at memory address: " << this << "\n";
}

int Entity::getId() const { return id_; }

const std::string& Entity::getName() const { return name_; }

// ---------------------------------------------------------
// Accommodation Base Implementation
// ---------------------------------------------------------
Accommodation::Accommodation(std::string name) : name_(std::move(name)) {}

void Accommodation::onEntityEnter(const Entity& entity) const {
    std::cout << "  -> " << entity.getName() << " (Address: " << &entity
              << ") entered " << name_ << ".\n";
}

void Accommodation::onEntityExit(const Entity& entity) const {
    std::cout << "  <- " << entity.getName() << " (Address: " << &entity
              << ") exited " << name_ << ".\n";
}

void Accommodation::addChild(std::shared_ptr<Accommodation> child) {
    if (!child) return;
    child->parent_ = this;
    children_.push_back(std::move(child));
}

void Accommodation::enter(std::unique_ptr<Entity> entity) {
    if (!entity) {
        throw std::invalid_argument("Cannot enter a null entity.");
    }
    onEntityEnter(*entity);
    occupants_[entity->getId()] = std::move(entity);
}

std::unique_ptr<Entity> Accommodation::exit(int entityId) {
    auto it = occupants_.find(entityId);
    if (it == occupants_.end()) {
        throw std::runtime_error("Entity not found in " + name_);
    }
    std::unique_ptr<Entity> entity = std::move(it->second);
    occupants_.erase(it);
    onEntityExit(*entity);
    return entity;
}

void Accommodation::transferTo(int entityId, Accommodation& destination) {
    std::unique_ptr<Entity> entity = this->exit(entityId);
    destination.enter(std::move(entity));
}

bool Accommodation::hasEntity(int entityId) const {
    return occupants_.find(entityId) != occupants_.end();
}

const Entity* Accommodation::getEntity(int entityId) const {
    auto it = occupants_.find(entityId);
    return (it != occupants_.end()) ? it->second.get() : nullptr;
}

std::size_t Accommodation::getOccupantCount() const {
    return occupants_.size();
}

const std::string& Accommodation::getName() const {
    return name_;
}

// ---------------------------------------------------------
// Composite Accommodations Implementation
// ---------------------------------------------------------
Building::Building(std::string name)
    : Accommodation("Building: " + std::move(name)) {}

Floor::Floor(int number)
    : Accommodation("Floor " + std::to_string(number)) {}

// ---------------------------------------------------------
// Leaf Accommodations Implementation
// ---------------------------------------------------------
Office::Office(std::string name)
    : Accommodation("Office: " + std::move(name)) {}

void Office::addChild(std::shared_ptr<Accommodation>) {
    throw std::logic_error("Leaf accommodation (Office) cannot contain sub-accommodations.");
}

void Office::onEntityEnter(const Entity& entity) const {
    std::cout << "  -> [Badge Scanned] " << entity.getName()
    << " (Address: " << &entity << ") clocked into " << name_ << ".\n";
}

Restaurant::Restaurant(std::string name)
    : Accommodation("Restaurant: " + std::move(name)) {}

void Restaurant::addChild(std::shared_ptr<Accommodation>) {
    throw std::logic_error("Leaf accommodation (Restaurant) cannot contain sub-accommodations.");
}

void Restaurant::onEntityEnter(const Entity& entity) const {
    std::cout << "  -> [Table Assigned] " << entity.getName()
    << " (Address: " << &entity << ") seated at " << name_ << ".\n";
}

GamePark::GamePark(std::string name)
    : Accommodation("Game Park: " + std::move(name)) {}

void GamePark::addChild(std::shared_ptr<Accommodation>) {
    throw std::logic_error("Leaf accommodation (GamePark) cannot contain sub-accommodations.");
}

void GamePark::onEntityEnter(const Entity& entity) const {
    std::cout << "  -> [Tokens Issued] " << entity.getName()
    << " (Address: " << &entity << ") entered " << name_ << ".\n";
}