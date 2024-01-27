// board.cpp
#include "board.h"
#include <iostream>

void board::CreateTask(const std::string& taskName, const std::string& taskDescription) {
    TaskList.push_back(Task(taskName, taskDescription));
}

void board::TaskDisplay() const {
    for (size_t i = 0; i < TaskList.size(); ++i) {
        std::cout << i + 1 << ". ";
        TaskList[i].DisplayTask();
        std::cout << "\n";
    }
}

void board::MoveTask(board& destinationBoard, size_t taskIndex) {
    if (taskIndex < TaskList.size()) {
        destinationBoard.TaskList.push_back(TaskList[taskIndex]);
        TaskList.erase(TaskList.begin() + taskIndex);
    }
}
