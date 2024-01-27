#include "Project.h"

// Імплементація конструктора
Project::Project(const std::string& name) : projectName(name) {}

// Імплементація методу GetProjectName
std::string Project::GetProjectName() const {
    return projectName;
}
