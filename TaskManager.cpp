#include "TaskManager.h"
#include <iostream>

//Constructor
TaskManager::TaskManager() {

}

//Deconstructor
TaskManager::~TaskManager() {

}

//Managing Tasks
void TaskManager::addTask(const Task& task) {
    taskList.push_back(task);
}

void TaskManager::removeTask(int taskId) {
    for(auto it = taskList.begin(); it < taskList.end(); it++) {
        if(it->getTaskId() == taskId) {
            taskList.erase(it);
            return;
        }
    }
}
void TaskManager::markComplete(int taskId) {
    for(auto it = taskList.begin(); it < taskList.end(); it++) {
        if(it->getTaskId() == taskId) {
            it->markComplete();
            return;
        }
    }

}

//Querying Tasks 
void TaskManager::displayTasks() const {
    if (taskList.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (const Task& task : taskList) {
        cout << "Task ID: " << task.getTaskId() 
         << "\nName: " << task.getTaskName() 
         << "\nDescription: " << task.getTaskDesc() 
         << "\nStatus: " << (task.getCompleteStatus() ? "Completed" : "Pending") 
         << endl;
    }

}

void TaskManager::searchTasks(const string& keyword) const
{
    bool found = false;

    for (const Task& task : taskList)
    {
        if (task.getTaskName().find(keyword) != string::npos)
        {
            std::cout << "\nTask ID: " << task.getTaskId()
                      << "\nName: " << task.getTaskName()
                      << "\nDescription: " << task.getTaskDesc()
                      << "\nStatus: "
                      << (task.getCompleteStatus() ? "Completed" : "Pending")
                      << "\n";

            found = true;
        }
    }

    if (!found) {
        cout << "No matching tasks found.\n";
    }
}

void TaskManager::showPendingTasks() const {
    for(auto it = taskList.begin(); it < taskList.end(); it++) {
        if(it->getCompleteStatus() == false) {
            cout << it->getTaskName() << endl;
        }
    }

}
void TaskManager::showCompletedTasks() const {
    for(auto it = taskList.begin(); it < taskList.end(); it++) {
        if(it->getCompleteStatus() == true) {
            cout << it->getTaskName() << endl;
        }
    }
}

void TaskManager::setTasks(const vector<Task>& loadedTasks) {
    taskList = loadedTasks;


    // Find the highest existing task ID
    for (Task& task : taskList) {

        if (task.getTaskId() >= task.getNextTaskId()) {
            task.setNextTaskId(task.getTaskId() + 1);
        }
    }
}

const vector<Task>& TaskManager::getTasks() const
{
    return taskList;
}