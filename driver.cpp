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
    ToDoList todo;
    DataList lists;

    lists.loadFromFile("lists.txt");
    bool inUse = true;
    string activeList;

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
                bool isFound = lists.searchList(listName);
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

            case 4: {
                if(!activeList.empty()) {
                    todo.completeTask();
                    todo.saveToFile(activeList + ".txt");
                } else {
                    cout << "\nYou have no list selected! Please choose a list.\n";
                }
                break;
            }


            case 5: {
                if(!activeList.empty()) {
                    todo.deleteTask();
                    todo.saveToFile(activeList + ".txt");
                } else {
                    cout << "\nYou have no list selected! Please choose a list.\n";
                }
                break;
            }

            case 6: {
                inUse = false;
                break;
            }

            default: {
                cout << "Invalid option! Please make another choice.\n";
                cin.clear();
                cin.ignore();
                break;
            }
        }
    }
}