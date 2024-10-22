#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
    ToDoList todo;
    todo.loadFromFile("todolist.txt");
    todo.display();
}