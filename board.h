// board.h
#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include "Task.h"

class board {
public:
    std::vector<Task> TaskList;

    // Додайте метод для створення завдань
    void CreateTask(const std::string& taskName, const std::string& taskDescription);

    // Видаліть параметр з декларації функції GetTask
    // Task GetTask();

    // Додайте метод для виведення завдань на дошку
    void TaskDisplay() const;

    // Додайте метод для переміщення завдань між колонками
    void MoveTask(board& destinationBoard, size_t taskIndex);
};

#endif //_BOARD_H
