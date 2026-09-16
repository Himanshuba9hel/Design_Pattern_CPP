#ifndef RESTAURANTS_H
#define RESTAURANTS_H
#include <ctime>
#include <unordered_map>
#include <string>
#include <utility>
#include <unordered_set>

class Customer;
class DiningRoom;
class Staff;
class Waiter;

enum class Location {
    Outside,
    Dining_Room,
    Waiting,
    Kitchen,
    Cabin
};

class Restaurants final
{
public:
    Restaurants();
    DiningRoom *dining_room = nullptr;

// Person inside Restaurant
protected:
    std::unordered_set<Customer*> customers;
    std::unordered_set<Staff*> staff;
    std::unordered_set<Waiter*> waiters;

// Operation on Person
public:
    void customerEntry(Customer* customer);
public:
    void addWaiter(Waiter* waiter);
    void addCustomer(Customer* customer);

    enum class States {
        Open,
        Break_Time,
        Under_Maintenance,
        Close
    };
    unsigned int seats = 0;

};

class RestaurantsSchedule {
public:
    RestaurantsSchedule();
// Time
protected:
    enum class Days {
        Sunday = 0,
        Monday = 1,
        Tuesday = 2,
        Wednesday = 3,
        Thursday = 4,
        Friday = 5,
        Saturday = 6
    };
    std::unordered_map<Days, std::pair<int, int>> working_days;

private:
    const char* days_str[7] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

};

#endif // RESTAURANTS_H
