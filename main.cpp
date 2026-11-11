#include <iostream>
#include "Task.h"
#include "TaskManager.h"
#include "FileStorage.h"

using namespace std;

int main() {
        // Create our objects
    TaskManager manager;
    FileStorage storage("tasks.txt");

    // Load previously saved tasks
    vector<Task> loadedTasks = storage.loadTasks();

    // Load tasks into TaskManager
    manager.setTasks(loadedTasks);

    int choice;

    do
    {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Remove Task\n";
        cout << "5. Search Tasks\n";
        cout << "6. View Completed Tasks\n";
        cout << "7. View Pending Tasks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
            {
                string name;
                string description;

                cout << "Enter task name: ";
                getline(cin, name);

                cout << "Enter task description: ";
                getline(cin, description);

                Task newTask(name, description);

                manager.addTask(newTask);

                break;
            }

            case 2:
                manager.displayTasks();
                break;

            case 3:
            {
                int taskID;

                cout << "Enter task ID to complete: ";
                cin >> taskID;

                manager.markComplete(taskID);
                break;
            }

            case 4:
            {
                int taskID;

                cout << "Enter task ID to remove: ";
                cin >> taskID;

                manager.removeTask(taskID);
                break;
            }

            case 5:
            {
                string keyword;

                cout << "Enter search keyword: ";
                getline(cin, keyword);

                manager.searchTasks(keyword);
                break;
            }

            case 6:
                manager.showCompletedTasks();
                break;

            case 7:
                manager.showPendingTasks();
                break;

            case 0:
                cout << "Saving tasks...\n";
                storage.saveTasks(manager.getTasks());
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid selection. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}