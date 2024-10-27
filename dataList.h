#ifndef DATALIST_H
#define DATALIST_H

#include <iostream>
#include <fstream>
#include <string>

//using namespace std;
template <typename T>
struct Task {
    T description;
    T priority;
    T status;
    Task* next;

    Task(T desc, T priority, T status) 
    : description(desc), priority(priority), status(status), next(nullptr) {}; // Constructor for Task

    bool operator==(const Task& other) const {
        return description == other.description;
    }

    friend std::ostream& operator<<(std::ostream& os, const Task& task){
        os << "Description: " << task.description
            << "\nPriority: " << task.priority
            << "\nStatus: " << task.status
            << "\n";
        return os;
    }

    bool operator<(const Task& other) const {
        if (priority == other.priority) {
            return description < other.description;
        }
        return priority < other.priority;
    }
};

class ToDoList {
private:
    Task<std::string>* head;

public:
    ToDoList() : head(nullptr) {};  // Constructor
    ~ToDoList();    // Destructor

    void loadFromFile(const std::string& fileName); // Load tasks from file
    void saveToFile(const std::string& fileName); // Save task to file
    void addTask(const std::string& description, std::string priority, std::string status); // Add a task to the list
    void searchTasks();
    void display() const;   // Display the list
    void clear();   // Clear the list
};

#endif