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
    Task(const string& taskName, const string& taskDesc);

    //Deconstructor
    ~Task();

    //Getters
    int getTaskId() const;
    int getNextTaskId() const;
    string getTaskName() const;
    string getTaskDesc() const;
    bool getCompleteStatus() const;

    //Setters
    void setTaskId(int id);
    void setTaskName(const string& name);
    void setTaskDesc(const string& desc);
    void setNextTaskId(int nextId);

    void markComplete();


 };
 #endif