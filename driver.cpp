#include <iostream>
#include "linkedList.h"
#include "dataList.h"

using namespace std;

void displayMenu() {
    cout << "\n======= TODO LIST PROGRAM =====\n";
    cout << "1. Choose List\n";
    cout << "2. View List\n";
    cout << "3. Add Task\n";
    cout << "4. Complete Task\n";
    cout << "5. Delete Task\n";
    cout << "6. Exit\n";
    cout << "================================================\n";
    cout << "Choose an option from the menu: ";
}

int main() {
    string x;
    ToDoList todo; // Intialize our todo list
    DataList lists; // Initialize our list of lists

    lists.loadFromFile("lists.txt"); // Loads our list list from a text file
    bool inUse = true;
    string activeList; // Holds the string for the active list

    // While inUse - we loop through the menu over and over until the exit condition is met
    while (inUse) {
        if(!activeList.empty()) {
            cout << "\nCurrent list is: " << activeList << endl;
        }
        displayMenu();
        
        int choice;
        cin >> choice;
        cin.ignore();
        

        // Switch statement to account for each choice given
        switch(choice) {
            case 1: {
                string listName;
                lists.display();
                cout << "Type the name of your list:\n";
                cin >> listName;
                bool isFound = lists.searchList(listName); // Searches to see if the list exits

                // If the list isn't found it creates it, if not loads the already created list
                if(!isFound){
                    lists.addList(listName);
                    lists.saveToFile("lists.txt", listName);
                    activeList = listName;
                } else {
                    lists.loadFromFile(listName + ".txt");
                    activeList = listName;
                }
                break;
            }
            // Sorts list by priority for any given list and displays it
            case 2: {
                if(!activeList.empty()) {
                    cout << "Sorting list by priority...\n" << endl;
                    todo.loadFromFile(activeList + ".txt");
                    quickSort(todo);
                    todo.display();
                } else {
                    cout << "\nYou have no list selected! Please choose a list.\n";
                }
                break;
            }
            // Adds a task of the users choosing and asks for priority of the task
            case 3: {
                if(!activeList.empty()) {
                    string task,priority,status;
                    status = "Incomplete";
                    cout << "What task would you like to add?\n";
                    getline(cin, task);
                    cout << "What is the task priority?\n";
                    getline(cin, priority);
                    todo.loadFromFile(activeList + ".txt");
                    cout << "The task you are adding is: " << task;
                    todo.addTask(task,priority,status);
                    todo.saveToFile(activeList + ".txt");
                } else {
                    cout << "\nYou have no list selected! Please choose a list.\n";
                }
                break;
            }
            // Allows the user to cycle through each task and ask if they want to mark it completed - 
            // without deleting the task for later viewing.
            case 4: {
                if(!activeList.empty()) {
                    todo.completeTask();
                    todo.saveToFile(activeList + ".txt");
                } else {
                    cout << "\nYou have no list selected! Please choose a list.\n";
                }
                break;
            }
            // Allows the user to cycle through tasks to delete them if they so choose.
            case 5: {
                if(!activeList.empty()) {
                    todo.deleteTask();
                    todo.saveToFile(activeList + ".txt");
                } else {
                    cout << "\nYou have no list selected! Please choose a list.\n";
                }
                break;
            }
            // Closes out of the program gracefully
            case 6: {
                inUse = false;
                break;
            }
            // Checks for invalid inputs for the menu selection.
            default: {
                cout << "Invalid option! Please make another choice.\n";
                cin.clear();
                cin.ignore();
                break;
            }
        }
    }
}