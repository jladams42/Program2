#ifndef DATALIST_H
#define DATALIST_H

#include <string>

using namespace std;

class DataList {
private:
    string** items;
    int size;

public:
    DataList(string filename);
    ~DataList();
    void getItems(string filename);
};

#endif