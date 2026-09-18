#include <iostream>

using namespace std;

class StoreTable
{

public:
    string* file_text = nullptr;
    void insert_to_file_text(string* file_text)
    {
        this->file_text = file_text;
    }
    virtual bool load_text(string* file_text){
        if(!file_text){
            cout<< "File text failed to load." << endl ;
            return false;
        }
        this->file_text = file_text;
        cout<< "File text is successfully loaded." << endl ;
        return true;
    }
    virtual bool save(){
        cout<< "File Saved." << endl ;
        return true;
    }
};

class StoreAsCSV : public StoreTable
{
public:
    bool load_text(string* file_text) override {
        if(!file_text){
            cout<< "CSV File text failed to load." << endl ;
            return false;
        }
        this->file_text = file_text;
        cout<< "CSV File text is successfully loaded." << endl ;
        return true;
    }
    bool save() override {
        cout<< "CSV File Saved." << endl ;
        return true;
    }
};

class StoreAsJSON : public StoreTable
{
public:
    bool load_text(string* file_text) override {
        if(!file_text){
            cout<< "JSON File text failed to load." << endl ;
            return false;
        }
        this->file_text = file_text;
        cout<< "JSON File text is successfully loaded." << endl ;
        return true;
    }
    bool save() override {
        cout<< "JSON File Saved." << endl ;
        return true;
    }
};

inline void result(bool x) {
    if(x)
        cout << "PASSED" << endl;
    else
        cout << "FAILED" << endl;
}

int main()
{
    string intro = "Hello My Name is Ram";
    StoreTable store;
    result(store.load_text(&intro));
    result(store.save());

    string csv_intro = "Hello My Name is Ram";
    StoreAsCSV csv_store;
    result(csv_store.load_text(&csv_intro));
    result(csv_store.save());

    string json_intro = "Hello My Name is Ram";
    StoreAsJSON json_store;
    result(json_store.load_text(&json_intro));
    result(json_store.save());

    return 0;
}
