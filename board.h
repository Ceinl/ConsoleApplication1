// board.h
#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include "Task.h"

class board {
public:
    std::vector<Task> TaskList;

    // ������� ����� ��� ��������� �������
    void CreateTask(const std::string& taskName, const std::string& taskDescription);

    // ������� �������� � ���������� ������� GetTask
    // Task GetTask();

    // ������� ����� ��� ��������� ������� �� �����
    void TaskDisplay() const;

    // ������� ����� ��� ���������� ������� �� ���������
    void MoveTask(board& destinationBoard, size_t taskIndex);
};

#endif //_BOARD_H
