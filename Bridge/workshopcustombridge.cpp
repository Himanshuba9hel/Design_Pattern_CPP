#include "workshopcustombridge.h"

WorkshopCustomBridge::WorkshopCustomBridge() {}

void Paint::work(Vehicle *vehicle) {
    // Downcast to determine the concrete vehicle type
    if (auto car = dynamic_cast<Car*>(vehicle)) {
        std::cout << "Paint Workshop: Applying Car-specific premium coating." << std::endl;
    }
    else if (auto bike = dynamic_cast<Bike*>(vehicle)) {
        std::cout << "Paint Workshop: Applying Bike-specific sport decals." << std::endl;
    }
    else if (auto autoRickshaw = dynamic_cast<Autorickshaw*>(vehicle)) {
        std::cout << "Paint Workshop: Applying standard yellow and green paint." << std::endl;
    } else {
        std::cout << "Paint Workshop: Applying default white paint." << std::endl;
    }
}

void Wheels::work(Vehicle *vehicle) {
    if (auto car = dynamic_cast<Car*>(vehicle)) {
        std::cout << "Wheels Workshop: Aligning 4 car tires." << std::endl;
    }
    else if (auto bike = dynamic_cast<Bike*>(vehicle)) {
        std::cout << "Wheels Workshop: Balancing 2 bike tires." << std::endl;
    }
    else if (auto autoRickshaw = dynamic_cast<Autorickshaw*>(vehicle)) {
        std::cout << "Wheels Workshop: Installing 3 commercial tires." << std::endl;
    } else {
        std::cout << "Wheels Workshop: default Installing 4 commercial tires." << std::endl;
    }
}
