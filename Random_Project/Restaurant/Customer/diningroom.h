#ifndef DININGROOM_H
#define DININGROOM_H
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Table;
class Customer;
struct TableNChair;

class DiningRoom final
{
public:
    DiningRoom(std::vector<TableNChair> *table_n_chairs);
    ~DiningRoom();
protected:
    std::unordered_set<Table*> tables;
    std::unordered_set<Customer*> standingCustomer;
    unsigned int chairs = 0;
};

struct TableNChair {
    unsigned int Tables = 0;
    unsigned int Chairs = 0;
};




#endif // DININGROOM_H
