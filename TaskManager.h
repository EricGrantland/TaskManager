#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <vector>
#include "Task.h"

using namespace std;

class TaskManager {
    private: 
        vector<Task> taskList;

    public:
    //Contructor
    TaskManager();

    //Deconstructor
    ~TaskManager();

    //Managing Tasks
    void addTask(const Task& task);
    void removeTask(int taskId);
    void markComplete(int taskId);

    //Querying Tasks 
    void displayTasks() const;
    void searchTasks(const string& keyword) const;
    void showPendingTasks() const;
    void showCompletedTasks() const;
    void setTasks(const vector<Task>& loadedTasks);
    const vector<Task>& getTasks() const;

};
#endif