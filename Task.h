#ifndef TASK_H
#define TASK_H
#include <string>
using namespace std;

 class Task {

    private:
    static int nextTaskId;
    int taskId;
    string taskName;
    string taskDesc;
    bool completeStatus;

    public:
    //Constructors
    Task();
    Task(string taskName, string taskDesc);

    //Deconstructor
    ~Task();

    //Getters
    int getTaskId();
    string getTaskName();
    string getTaskDesc();
    bool getCompleteStatus();

    //Setters
    void setTaskId(int id);
    void setTaskName(string name);
    void setTaskDesc(string desc);
    
    void Task::markComplete();


 };
 #endif