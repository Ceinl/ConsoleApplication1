// Task.h
#ifndef _TASK_H
#define _TASK_H
#include <string>

class Task {
public:
    std::string name;
    std::string description;

    // ������� �����������
    Task(const std::string& taskName = "", const std::string& taskDescription = "");

    // ������� ����� ��� ��������� ���������� ��� ��������
    void DisplayTask() const;
};

#endif //_TASK_H
