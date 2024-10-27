#include "dataList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;
// Constructor for Task
// template <typename T>
// Task<T>::Task(T desc) : description(desc), next(nullptr) {}

// // Constructor for DataList
// DataList::DataList() : head(nullptr) {}

// Destructor to free memory
DataList::~DataList() {
    clear();
}

// Function to load tasks from file into the linked list
void DataList::loadFromFile(const std::string& fileName) {
    std::ifstream inFile("lists.txt");
    if (!inFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }

    std::string title;
    while (getline(inFile, title)) {
        addList(title);
    }

    inFile.close();
}

// Function to save the linked list to a file (append mode)
void DataList::saveToFile(const std::string& fileName, const std::string& title) {
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }

    List<std::string>* current = head;
    while (current != nullptr) {
        bool listExists = false;
        List<std::string>* check = head;

        while (check != current) {
            if (*current == *check){
                listExists = true;
                break;
            }
            check = check->next;
        }

        if (!listExists) {
            outFile << current->title << std::endl; 
        }
        current = current->next;
    }


    outFile.close();
    std::cout << "Tasks have been saved!" << std::endl;
}

// Function to add a new task to the linked list
void DataList::addList(const std::string& title) {
    List<std::string>* newList = new List<std::string>(title);

    if (head == nullptr) {
        head = newList;
    } else {
        List<std::string>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newList;
    }
}

// Function to display the linked list
void DataList::display() const {
    int i = 1;
    List<std::string>* temp = head;
    if (temp == nullptr) {
        std::cout << "You have no lists!" << std::endl;
        return;
    }
    while (temp != nullptr) {
        std::cout << i << ". "<< temp->title << std::endl;
        temp = temp->next;
        i++;
    }
}

// Function to clear the linked list and free memory
void DataList::clear() {
    while (head != nullptr) {
        List<std::string>* temp = head;
        head = head->next;
        delete temp;
    }
}

bool DataList::searchList(std::string search) {
    List<std::string>* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->title == search) {
            cout << "This list matches your list " << current->title << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "No matches were found. The list doesn't exist. Creating a new one...\n";
        std::ofstream file(search + ".txt");
        if(file.is_open()) {
            cout << "Created a new list called " << search << endl;
            file.close();
        } else {
            cerr << "Error creating the list!\n";
        }
    return false;
    }

return true;
}