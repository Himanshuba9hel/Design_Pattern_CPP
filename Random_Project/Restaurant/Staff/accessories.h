#ifndef ACCESSORIES_H
#define ACCESSORIES_H

#include <unordered_set>


class Item;
class Staff;

class Accessories
{
public:
    Accessories(Staff* holder);
protected:
    //Staff* holder = nullptr;
    Staff* holder;
    std::unordered_set<Item*> ItemList;
    Item* give(Staff* recipient);
    void take(Item* item);
};

enum class ItemType {
    OrderList,
    Pen,
    Tray
};

class Item
{
protected:
    ItemType type;
public:
    virtual void getType() = 0;
    virtual void functionality() = 0;
};

class OrderList: public Item
{
public:
    void getType() override { type = ItemType::OrderList;}
    void functionality() override { }
};

class Tray: public Item
{
public:
    void getType() override { type = ItemType::Tray;}
    void functionality() override { }
};

class Pen: public Item
{
public:
    void getType() override { type = ItemType::Pen;}
    void functionality() override { }
};


#endif // ACCESSORIES_H
