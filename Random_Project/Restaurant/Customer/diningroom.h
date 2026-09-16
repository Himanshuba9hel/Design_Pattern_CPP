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
protected:
    std::unordered_set<Table*> tables;
    std::unordered_set<Customer*> standingCustomer;
    unsigned int chairs = 0;
};

struct TableNChair {
    unsigned int Tables = 0;
    unsigned int Chairs = 0;
};

class Table
{
public:
    Table(unsigned int maximum_chairs);
    std::unordered_map<unsigned int, Customer*> chairs_customer_arrangement;
};


#endif // DININGROOM_H
