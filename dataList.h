#ifndef DATALIST_H
#define DATALIST_H

#include <string>

using namespace std;

template <typename T>
struct List {
    T title;
    List* next;

    List(T title) : title(title), next(nullptr) {};
    bool operator==(const List& other) const {
        return title == other.title;
    }
};

class DataList {
private:
    List<std::string>* head;

public:
    DataList() : head (nullptr) {};
    ~DataList();

    void loadFromFile(const std::string& fileName);     
    void saveToFile(const std::string& fileName, const std::string& title);
    void addList(const std::string& title);
    bool searchList(std::string search);       
    void display() const;            
    void clear();   
};

#endif