#ifndef MENU_H
#define MENU_H
#include <unordered_set>

class Menu
{
public:
    Menu();
};

class Dish
{
    enum class Availability {
        Available,
        Unavailable,
        Wait
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
    std::unordered_set<Ingredient> Ingredients;

};

#endif // MENU_H
