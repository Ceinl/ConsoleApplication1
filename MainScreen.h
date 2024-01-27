// MainScreen.h
#ifndef _MAINSCREEN_H
#define _MAINSCREEN_H

#include <vector>
#include "Project.h"

class MainScreen {
private:
    std::vector<Project*> MyProject;

public:
    const std::vector<Project*>& getMyProject() const {
        return MyProject;
    }


public:
    void OpenProject();
    void CreateProject();
    void DeleteProject();
    void CreateTask();
    void DisplayTasks() const;
    void MoveTask();
};

#endif // _MAINSCREEN_H
//zroz
