#include "menu.h"

Menu::Menu() {}


void Pantry::setAvailabilityOfIngredient
    (Ingredient ingredient, Availability status)
{
    list_ingredient_availability[ingredient] = status;
}

Availability Pantry::getAvailabilityOfIngredient(Ingredient ingredient)
{
    return list_ingredient_availability[ingredient];
}

Availability Pantry::listOfIngredientIsAvailable(std::unordered_set<Ingredient> &ingredient_list)
{
    for(auto ingredient : ingredient_list)
    {
        if(list_ingredient_availability[ingredient] ==
            Availability::Unavailable)
            return Availability::Unavailable;
    }
    return Availability::Available;
}



std::unordered_set<Dish> Dishes::list_dish()
{
    std::unordered_set<Dish> list;
    for(auto dish_availability: list_dish_availability){
        if(dish_availability.second == Availability::Available)
            list.insert(dish_availability.first);
    }
    return list;
}
