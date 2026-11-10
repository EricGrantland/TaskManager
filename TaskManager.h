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
    void addTask(Task& task);
    void removeTask(int taskId);
    void markComplete(int taskId);

    //Querying Tasks 
    void displaytasks();
    void showPendingTasks();
    void showCompletedTasks();

};
#endif