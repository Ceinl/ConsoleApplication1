// Task.cpp
#include "Task.h"
#include <iostream>

Task::Task(const std::string& taskName, const std::string& taskDescription)
    : name(taskName), description(taskDescription) {}

void Task::DisplayTask() const {
    std::cout << "Task: " << name << "\nDescription: " << description << "\n";
}
