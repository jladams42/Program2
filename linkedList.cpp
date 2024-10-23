#include "linkedList.h"
#include <iostream>
#include <fstream>

//using namespace std;

// Constructor for Task
// template <typename T>
// Task<T>::Task(T desc) : description(desc), next(nullptr) {}

// // Constructor for ToDoList
// ToDoList::ToDoList() : head(nullptr) {}

// Destructor to free memory
ToDoList::~ToDoList() {
    clear();
}

// Function to load tasks from file into the linked list
void ToDoList::loadFromFile(const std::string& fileName) {
    std::ifstream inFile("todolist.txt");
    if (!inFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }

    std::string description;
    while (getline(inFile, description)) {
        addTask(description);
    }

    inFile.close();
}

// Function to save the linked list to a file (append mode)
void ToDoList::saveToFile(const std::string& fileName, const std::string& description) {
    std::ofstream outFile(fileName, std::ios::app);
    if (!outFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }

    outFile << description << std::endl;

    outFile.close();
}

// Function to add a new task to the linked list
void ToDoList::addTask(const std::string& description) {
    Task<std::string>* newTask = new Task<std::string>(description);

    if (head == nullptr) {
        head = newTask;
    } else {
        Task<std::string>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

// Function to display the linked list
void ToDoList::display() const {
    Task<std::string>* temp = head;
    if (temp == nullptr) {
        std::cout << "Your to-do list is empty!" << std::endl;
        return;
    }
    while (temp != nullptr) {
        std::cout << "- " << temp->description << std::endl;
        temp = temp->next;
    }
}

// Function to clear the linked list and free memory
void ToDoList::clear() {
    while (head != nullptr) {
        Task<std::string>* temp = head;
        head = head->next;
        delete temp;
    }
}