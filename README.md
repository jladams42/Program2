# TODO List Program Documentation

This program is a simple CLI-based TODO list manager that allows users to create, view, and manage multiple lists of tasks. Each task has a description, priority, and completion status. The program provides an interactive menu for selecting a list, viewing tasks, adding tasks, marking tasks as completed, and deleting tasks.

## Program Files and Their Responsibilities

### 1. **Drive.cpp**
   - **Purpose**: Controls the main logic of the program.
   - **Responsibilities**:
      - Displays the interactive menu and handles user input.
      - Manages active lists by allowing the user to select, create, and load lists from files.
      - Uses a `while` loop to continuously show the menu and allow the user to select options until they choose to exit.
      - Calls functions to add, view, complete, or delete tasks based on user choice.
      - Ensures selected tasks are saved and the program exits gracefully.

### 2. **linkedList.cpp and linkedList.h**
   - **Purpose**: Manages lists of tasks, loads them from files, and allows new lists to be created and saved.
   - **Responsibilities**:
      - Defines a `LinkedList` class to hold a list of tasks, allowing efficient task management.
      - Provides functions to load tasks from a file into a linked list and save them back to files when modified.
      - Supports the ability to add new lists dynamically and persist them in text files for future sessions.
      - Responsible for maintaining the data structure for each list and ensuring that each list can be accessed, modified, and saved.

### 3. **dataList.cpp and dataList.h**
   - **Purpose**: Handles task management within a specific list, including task details and task states.
   - **Responsibilities**:
      - Defines a `DataList` class with attributes for each task: description, priority, and completion status.
      - Provides functions to add new tasks, view tasks, mark tasks as complete, and delete tasks from the list.
      - Manages the priority of tasks, allowing tasks to be sorted based on priority.
      - Saves task data in the specified list text file and allows for reloading from file when a list is revisited.
      - Supports the concept of task status (`Incomplete` or `Complete`) and updates the file whenever task status changes.

### 4. **Makefile**
   - **Purpose**: Automates the build process for compiling the TODO List Program.
   - **Responsibilities**:
      - Defines compilation rules and dependencies for the program files.
      - Ensures that any changes to source files (`Drive.cpp`, `linkedList.cpp`, `dataList.cpp`) are reflected in the final executable by specifying build instructions.
      - Commonly includes commands like `make all` to build the entire program, and `make clean` to remove compiled files and reset the build environment.

### 5. **Test Case File**
   - **Purpose**: Provides test cases for verifying program functionality.
   - **Responsibilities**:
      - Contains various scenarios to ensure each function works correctly, such as creating lists, adding tasks, marking tasks as completed, and deleting tasks.
      - Tests for boundary cases and edge cases, like trying to complete or delete tasks from an empty list or handling invalid user inputs in the menu.
      - Helps in validating that the program meets requirements and that updates to the code do not break existing functionality.

