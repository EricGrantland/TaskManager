#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <vector>
#include <string>
#include "Task.h"
using namespace std;

class FileStorage
{
private:
    string filename;

public:
    // Constructor
    FileStorage(const string& filename);

    // File operations
    void saveTasks(const vector<Task>& tasks) const;
    vector<Task> loadTasks() const;
};

#endif