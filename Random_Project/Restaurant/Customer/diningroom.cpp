#include "diningroom.h"
class Table;
DiningRoom::DiningRoom(std::vector<TableNChair> *table_n_chairs)
{
    if(!table_n_chairs)
        return;
    for(const auto& [Tables, Chairs] : *table_n_chairs)
    {
        if(Tables != 0){
            for(auto i = 0; i < Tables; ++i){
                Table* table = new Table(Chairs);
                tables.insert(table);
            }
        }else{
            chairs += Chairs;
        }
    }
}

Table::Table(unsigned int maximum_chairs)
{
    chairs_customer_arrangement.reserve(maximum_chairs);
}