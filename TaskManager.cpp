#include "TaskManager.h"
#include <iostream>

//Constructor
TaskManager::TaskManager() {

}

//Deconstructor
TaskManager::~TaskManager() {

}

//Managing Tasks
void TaskManager::addTask(Task& task) {
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
void TaskManager::displaytasks() {
    for(auto it = taskList.begin(); it < taskList.end(); it++) {
        cout << it->getTaskName() << endl;
    }

}
void TaskManager::showPendingTasks() {
    for(auto it = taskList.begin(); it < taskList.end(); it++) {
        if(it->getCompleteStatus() == false) {
            cout << it->getTaskName() << endl;
        }
    }

}
void TaskManager::showCompletedTasks() {
    for(auto it = taskList.begin(); it < taskList.end(); it++) {
        if(it->getCompleteStatus() == true) {
            cout << it->getTaskName() << endl;
        }
    }
}