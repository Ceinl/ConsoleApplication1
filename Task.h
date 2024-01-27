// Task.h
#ifndef _TASK_H
#define _TASK_H
#include <string>

class Task {
public:
    std::string name;
    std::string description;

    // Додайте конструктор
    Task(const std::string& taskName = "", const std::string& taskDescription = "");

    // Додайте метод для виведення інформації про завдання
    void DisplayTask() const;
};

#endif //_TASK_H
