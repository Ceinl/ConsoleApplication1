#include "Project.h"

// ������������� ������������
Project::Project(const std::string& name) : projectName(name) {}

// ������������� ������ GetProjectName
std::string Project::GetProjectName() const {
    return projectName;
}
