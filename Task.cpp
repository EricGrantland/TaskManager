#include "Task.h"

int Task::nextTaskId = 1;

//Default Constructor
Task::Task() {
    taskId = 0;
    taskName = "";
    taskDesc = "";
}

//Param Const
Task::Task(const string& name, const string& desc) {
    taskId = nextTaskId++;
    taskName = name;
    taskDesc = desc;
    completeStatus = false;
}

//Deconstructor
Task::~Task() {

}

//Getters
int Task::getTaskId() const {
    return taskId;
}

string Task::getTaskName() const {
    return taskName;
}
string Task::getTaskDesc() const {
    return taskDesc;
}

bool Task::getCompleteStatus() const {
    return completeStatus;
}

int Task::getNextTaskId() const {
    return nextTaskId;
}

//Setters
void Task::setTaskId(int id) {
    taskId = id;
}
void Task::setTaskName(const string& name) {
    taskName = name;
}
void Task::setTaskDesc(const string& desc) {
    taskDesc = desc;
}

void Task::setNextTaskId(int nextId) {
    nextTaskId = nextId;
}

void Task::markComplete() {
    completeStatus = true;
}