#include "FileStorage.h"
#include <fstream>
#include <iostream>
#include <iomanip>

// Constructor
FileStorage::FileStorage(const string& filename)
    : filename(filename) {
}

// Save tasks to file
void FileStorage::saveTasks(const vector<Task>& tasks) const {
    ofstream outFile(filename);

    // Check if file opened successfully
    if (!outFile)
    {
        cerr << "Error opening file for saving.\n";
        return;
    }

    // Write each task to the file
    for (const Task& task : tasks)
    {
        outFile << task.getTaskId() << " "
                << boolalpha << task.getCompleteStatus() << " "
                << quoted(task.getTaskName()) << " "
                << quoted(task.getTaskDesc()) << "\n";
    }

    cout << "Tasks saved successfully.\n";
}

// Load tasks from file
vector<Task> FileStorage::loadTasks() const {
    vector<Task> loadedTasks;

    ifstream inFile(filename);

    // Check if file opened successfully
    if (!inFile)
    {
        cerr << "Error opening file for loading.\n";
        return loadedTasks;
    }

    int id;
    bool completed;
    string name;
    string description;

    // Read each task from the file
    while (inFile >> id
                  >> boolalpha >> completed
                  >> quoted(name)
                  >> quoted(description))
    {
        Task task(name, description);

        task.markComplete();

        loadedTasks.push_back(task);
    }

    return loadedTasks;
}