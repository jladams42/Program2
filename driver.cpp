#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
    string x;
    ToDoList todo;
    todo.loadFromFile("todolist.txt");
    cout << "Do you wish to add a task to the list?\n"; 
    cin >> x;
    cin.ignore();
    if (x == "yes"){
        string task;
        cout << "Enter the task now?\n";
        getline(cin, task);
        todo.addTask(task);
        todo.saveToFile("todolist.txt", "[ ] " + task);
    }
    
    todo.display();
}