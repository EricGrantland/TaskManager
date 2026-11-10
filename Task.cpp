#include "Task.h"

//Default Constructor
Task::Task() {
    taskId = 0;
    taskName = "";
    taskDesc = "";
}

//Param Const
Task::Task(string name, string desc) {
    taskId = nextTaskId++;
    taskName = name;
    taskDesc = desc;
    completeStatus = false;
}

//Deconstructor
Task::~Task() {

}

//Getters
int Task::getTaskId() {
    return taskId;
}

string Task::getTaskName() {
    return taskName;
}
string Task::getTaskDesc() {
    return taskDesc;
}

bool Task::getCompleteStatus() {
    return completeStatus;
}

//Setters
void Task::setTaskId(int id) {
    taskId = id;
}
void Task::setTaskName(string name) {
    taskName = name;
}
void Task::setTaskDesc(string desc) {
    taskDesc = desc;
}

void Task::markComplete() {
    completeStatus = true;
}