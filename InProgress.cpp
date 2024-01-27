// InProgress.cpp
#include "InProgress.h"

void InProgress::MoveToCompleted(board& destinationBoard, size_t taskIndex) {
    if (taskIndex < TaskList.size()) {
        destinationBoard.TaskList.push_back(TaskList[taskIndex]);
        TaskList.erase(TaskList.begin() + taskIndex);
    }
}
