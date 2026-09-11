#ifndef MENU_H
#define MENU_H
#include <unordered_map>
#include <string>
#include <unordered_set>

enum class Availability {
    Available = true,
    Unavailable = false,
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

class Pantry {
protected:
    // Default List
    std::unordered_map<Ingredient,Availability> list_ingredient_availability =
    {{Ingredient::Amaranth_Leaves, Availability::Available},
     {Ingredient::Bringal, Availability::Available},
     {Ingredient::Beetroot, Availability::Available},
     {Ingredient::Carrot, Availability::Available},
     {Ingredient::Onion, Availability::Available},
     {Ingredient::Potato, Availability::Available},
     {Ingredient::Pumpkin, Availability::Available},
     {Ingredient::Radish, Availability::Available},
     {Ingredient::Ridge_Gourd, Availability::Available},
     {Ingredient::Spinach, Availability::Available},
     {Ingredient::Sweet_Corn, Availability::Unavailable},
     {Ingredient::Tomato, Availability::Available},
     {Ingredient::Turnip, Availability::Unavailable}
    };
protected:
    void setAvailabilityOfIngredient(Ingredient ingredient, Availability status);
    Availability getAvailabilityOfIngredient(Ingredient ingredient);
    Availability listOfIngredientIsAvailable(std::unordered_set<Ingredient> &ingredient_list);
};

class Menu
{
public:
    Menu();
};

class Dishes
{
public:
    Dishes();
    enum class Dish {
        Curry,
        Pasta,
        Bringal_Dish,
        Lanten,
        Potato_Bread
    };
    std::unordered_map<Dish,std::unordered_set<Ingredient>> list_dish_ingredient =
        {
        {Dish::Curry,
            {Ingredient::Tomato,
            Ingredient::Onion,
            Ingredient::Sweet_Corn}},
        {Dish::Pasta,
            {Ingredient::Tomato,
            Ingredient::Onion}},
        {Dish::Bringal_Dish,
            {Ingredient::Pumpkin,
            Ingredient::Sweet_Corn,
            Ingredient::Radish}},
        {Dish::Lanten,
            {Ingredient::Turnip,
            Ingredient::Tomato,
            Ingredient::Sweet_Corn}},
        {Dish::Potato_Bread,
            {Ingredient::Spinach,
            Ingredient::Potato}},
        };
};

#endif // MENU_H
