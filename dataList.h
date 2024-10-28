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
    // Friend function to display the Task node
    friend std::ostream& operator<<(std::ostream& os, const Task& task){
        os << "Description: " << task.description
            << "\nPriority: " << task.priority
            << "\nStatus: " << task.status
            << "\n";
        return os;
    }
    // Overload operator for priority comparison
    bool operator<(const Task& other) const {
        if (priority == other.priority) {
            return description < other.description;
        }
        return priority < other.priority;
    }
    // Overload operator for priority comparison
    bool operator>(const Task& other) const {
    if (priority == other.priority) {
        return description > other.description;
    }
    return priority > other.priority;
    }
};

class ToDoList {
private:
    Task<std::string>* head;
    // List of definitions used by the ToDoList Class for the quicksort algorithm
    Task<std::string>* getTail(Task<std::string>* node); // Helper function to get the tail node
    Task<std::string>* partition(Task<std::string>* low, Task<std::string>* high, Task<std::string>** newHead, Task<std::string>** newEnd); // Helper function to divide list into 2 parts
    Task<std::string>* quickSortRecurse(Task<std::string>* head, Task<std::string>* end); // Used to call the sorting algoirhtm recursively until properly sorted

public:
    ToDoList() : head(nullptr) {};  // Constructor
    ~ToDoList();    // Destructor

    void loadFromFile(const std::string& fileName); // Load tasks from file
    void saveToFile(const std::string& fileName); // Save task to file
    void addTask(const std::string& description, std::string priority, std::string status); // Add a task to the list
    void deleteTask();
    void completeTask();
    void display() const;   // Display the task list
    void clear();   // Clear the task

    friend void quickSort(ToDoList& list);
};

#endif