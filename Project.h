#ifndef _PROJECT_H
#define _PROJECT_H

#include "InProgress.h"
#include "ToDo.h"
#include "Completed.h"
#include <string>

class Project {
private:
    std::string projectName;

public:
    InProgress myInProgress;
    ToDo myToDo;
    Completed myCompleted;

    Project(const std::string& name = "");

    std::string GetProjectName() const;
};

#endif // _PROJECT_H
