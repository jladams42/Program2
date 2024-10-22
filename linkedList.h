#include <iostream>
#include <fstream>
#include <string>

//using namespace std;

struct Task {
    std::string description;
    Task* next;

    Task(std::string desc); // Constructor for Task
};

class ToDoList {
private:
    Task* head;

public:
    ToDoList();          // Constructor
    ~ToDoList();         // Destructor

    void loadFromFile(const std::string& fileName);        // Load tasks from file
    void saveToFile(const std::string& fileName, const std::string& description); // Save task to file
    void addTask(const std::string& description);          // Add a task to the list
    void display() const;                             // Display the list
    void clear();                                     // Clear the list
};