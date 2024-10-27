#include "dataList.h"
#include <iostream>
#include <fstream>

//using namespace std;

// Destructor to free memory
ToDoList::~ToDoList() {
    clear();
}

// Function to load tasks from file into the linked list
void ToDoList::loadFromFile(const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }

    std::string description, priority, status;
    while (getline(inFile, description) && getline(inFile, priority) && getline(inFile, status)) {
        addTask(description, priority, status);
    } 

    inFile.close();
}

// Function to save the linked list to a file (append mode)
void ToDoList::saveToFile(const std::string& fileName) {
    std::ofstream outFile(fileName);

    if (!outFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }

    Task<std::string>* current = head;

    while (current != nullptr) {
        bool taskExists = false;
        Task<std::string>* check = head;

        while (check != current) {
            if (*current == *check){
                taskExists = true;
                break;
            }
            check = check->next;
        }

        if (!taskExists) {
            outFile << current->description << std::endl;
            outFile << current->priority << std::endl;
            outFile << current->status << std::endl; 
        }
        current = current->next;
    }


    outFile.close();
    std::cout << "Tasks have been saved!" << std::endl;
}

// Function to add a new task to the linked list
void ToDoList::addTask(const std::string& description, std::string priority, std::string status) {
    Task<std::string>* temp = head;
    while (temp != nullptr){
        if (temp->description == description) {
            std::cout << "Task already exists: " << description << std:: endl;
            return;
        }
        temp = temp->next;
    }


    Task<std::string>* newTask = new Task<std::string>(description, priority, status);

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
    Task<std::string>* current = head;
    if (current == nullptr) {
        std::cout << "Your to-do list is empty!" << std::endl;
        return;
    }
    std::cout << "\n=============\n";
    std::cout << "\nTODO LIST\n";
    while (current != nullptr) {
        std::cout << *current << "\n"; 
        current = current->next;
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

void ToDoList::deleteTask() {
    if (head == nullptr) {
        std::cout << "The task list is empty." << std::endl;
        return;
    }

    Task<std::string>* current = head;
    Task<std::string>* prev = nullptr;

    while (current != nullptr) {
        std::cout << "Task: " << current->description << std::endl;
        std::cout << "Do you wish to delete this task? (y/n): ";
        char response;
        std:: cin >> response;

        if (response == 'y' || response == 'Y') {
            if(prev == nullptr){
                // For if the head needs deletion
                head = current->next;
                delete current;
                current = head;
            } else {
                // Middle or the last task deletion
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            std::cout << "Task deleted." << std::endl;
        } else {
            // Move on to the next task
            prev = current;
            current = current->next;
        }
    }
}

void ToDoList::completeTask() {
    if (head == nullptr) {
        std::cout << "The task list is empty." << std::endl;
        return;
    }

    Task<std::string>* current = head;

    while (current != nullptr) {
        std::cout << "Task: " << current->description << std::endl;
        std::cout << "Current Status: " << current->status << std::endl;
        std::cout << "Mark this task completed? (y/n): ";
        char response;
        std:: cin >> response;

        if (response == 'y' || response == 'Y') {
            current->status =  "Complete";
            std::cout << "Task status updated to Complete!" << std::endl;
        }

        current = current->next;
    }
}

void quickSort(ToDoList& list) {
    list.head = list.quickSortRecurse(list.head, list.getTail(list.head));
}

Task<std::string>* ToDoList::getTail(Task<std::string>* node) {
    while (node && node->next) {
        node = node->next;
    }
    return node;
}

Task<std::string>* ToDoList::partition(Task<std::string>* low, Task<std::string>* high, Task<std::string>** newHead, Task<std::string>** newEnd) {
    Task<std::string>* pivot = high;
    Task<std::string>* prev = nullptr, *cur = low, *tail = pivot;

    while(cur != pivot) {
        if (*cur < *pivot) {
            if (!*newHead) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Task<std::string>* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if (!*newHead) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Task<std::string>* ToDoList::quickSortRecurse(Task<std::string>* head, Task<std::string>* end) {
    if (!head || head == end){
        return head;
    }

    Task<std::string> *newHead = nullptr, *newEnd = nullptr;
    Task<std::string>* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Task<std::string>* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecurse(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot; 
    }

    pivot->next = quickSortRecurse(pivot->next, newEnd);
    return newHead;
}