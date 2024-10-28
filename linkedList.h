#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

template <typename T>
struct List {
    T title;
    List* next;

    List(T title) : title(title), next(nullptr) {}; // Constructor of the list node

    // Operator over overload to compare the list node 'title' attributes
    bool operator==(const List& other) const {
        return title == other.title;
    }
};

class DataList {
private:
    List<std::string>* head;

public:
    DataList() : head (nullptr) {}; // Constructor for head node of an empty list
    ~DataList(); // Destructor clears the lsit

    void loadFromFile(const std::string& fileName); // Uses file name to load from a file
    void saveToFile(const std::string& fileName, const std::string& title); // Uses file name and title to save to text file as a db
    void addList(const std::string& title); // Add text file names to the list
    bool searchList(std::string search); // Lets you search through the list using a string
    void display() const; // Displays the list of lists        
    void clear(); // Clears the list of lists
};

#endif