#ifndef RESTAURANTS_H
#define RESTAURANTS_H
#include <ctime>
#include <unordered_map>
#include <string>
#include <utility>

class Restaurants
{
public:
    Restaurants();
    enum class States {
        Open,
        Break_Time,
        Under_Maintenance,
        Close
    };

    unsigned int seats = 0;

};

class Restaurants_Schedule {
public:
    Restaurants_Schedule();
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
