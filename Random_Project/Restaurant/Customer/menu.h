#ifndef MENU_H
#define MENU_H
#include <unordered_map>
#include <string>

class Pantry {
public:
    enum class Availability {
        Available,
        Unavailable
    };
    enum class Ingredient {
        Amaranth_Leaves,
        Bringal,
        Beetroot,
        Carrot,
        Onion,
        Potato,
        Pumpkin,
        Radish,
        Ridge_Gourd,
        Spinach,
        Sweet_Corn,
        Tomato,
        Turnip,
    };
    std::unordered_map<Ingredient,Availability> ingredient_availability;
};

class Menu
{
public:
    Menu();
};

class Dish : public Pantry
{
public:
    Dish();
    enum class Dishes {
        Curry,
        Pasta,
        Bringal,
        Lanten,
        Potato_Bread
    };
protected:
    std::string name;
    // std::unordered_map<Ingredient> Ingredients;
};

#endif // MENU_H
