#include "MainScreen.h"
#include <iostream>
#include <algorithm>
#include <cassert>
/**
 * @brief Creates a new project and adds it to the list.
 *
 * This function creates a new project and adds it to the list
 * of projects in MainScreen.
 *
 * @return void
 */
void MainScreen::OpenProject() {
    std::cout << "\t\t\tEnter the name of the project to open: ";
    std::string projectName;
    std::cin >> projectName;

    // Пошук проекту за ім'ям
    auto it = std::find_if(MyProject.begin(), MyProject.end(),
        [projectName](const Project* project) {
            return project->GetProjectName() == projectName;
        });

    // Перевірка, чи проект знайдено
    if (it != MyProject.end()) {
        // Тут ви можете додати код для обробки "відкриття" проекту
        std::cout << "Opening project: " << (*it)->GetProjectName() << "\n";
        // Додайте додатковий код за необхідності
    }
    else {
        std::cout << "Project not found.\n";
    }
}


void MainScreen::CreateProject() {
    // Запитайте користувача ввести назву проекту
    std::string projectName;
    std::cout << "\t\t\tEnter the name of the new project: ";
    std::cin >> projectName;

    // Створіть новий проект з введеною назвою та додайте його до списку
    MyProject.push_back(new Project(projectName));

    std::cout << "Available Projects:\n";
    for (size_t i = 0; i < MyProject.size(); ++i) {
        std::cout << i + 1 << ". " << MyProject[i]->GetProjectName() << "\n";
    }
}

/**
 * @brief Deletes a project from the list.
 *
 * This function prompts the user to select a project to delete
 * and removes it from the list of projects.
 *
 * @return void
 */
void MainScreen::DeleteProject() {
    // Display a list of available projects
    std::cout << "Available Projects:\n";
    for (size_t i = 0; i < MyProject.size(); ++i) {
        std::cout << i + 1 << ". " << MyProject[i]->GetProjectName() << "\n";
    }

    // Prompt the user to select a project to delete
    size_t projectIndexToDelete;
    std::cout << "\t\t\tEnter the number of the project to delete (0 to cancel): ";
    std::cin >> projectIndexToDelete;

    // Validate user input
    if (projectIndexToDelete >= 1 && projectIndexToDelete <= MyProject.size()) {
        // Delete the selected project
        delete MyProject[projectIndexToDelete - 1];
        MyProject.erase(MyProject.begin() + projectIndexToDelete - 1);
        std::cout << "Project deleted successfully.\n";
    }
    else if (projectIndexToDelete == 0) {
        std::cout << "Deletion canceled.\n";
    }
    else {
        std::cout << "Invalid input. Deletion canceled.\n";
    }
}

void MainScreen::CreateTask() {
    std::cout << "\t\t\tEnter the name of the task: ";
    std::string taskName;
    std::cin >> taskName;

    std::cout << "\t\t\tEnter the description of the task: ";
    std::string taskDescription;
    std::cin.ignore(); // Clear newline from buffer
    std::getline(std::cin, taskDescription);

    DisplayTasks();

    std::cout << "\t\t\tChoose a project to add the task to (enter project number):";
    size_t projectIndex;
    std::cin >> projectIndex;

    if (projectIndex >= 1 && projectIndex <= MyProject.size()) {
        MyProject[projectIndex - 1]->myToDo.CreateTask(taskName, taskDescription);

        // Додайте перевірку на наявність завдань в списку ToDo
        assert(!MyProject[projectIndex - 1]->myToDo.TaskList.empty() && "CreateTask test failed");

        std::cout << "\nTask created successfully.\n";
    }
    else {
        std::cout << "Invalid project number. Task creation canceled.\n";
    }
}



void MainScreen::DisplayTasks() const {
    for (const auto& project : MyProject) {
        std::cout << "Tasks for Project: " << project->GetProjectName() << "\n";
        std::cout << "ToDo:\n";
        project->myToDo.TaskDisplay();
        std::cout << "InProgress:\n";
        project->myInProgress.TaskDisplay();
        std::cout << "Completed:\n";
        project->myCompleted.TaskDisplay();
        std::cout << "\n";
    }
}


void MainScreen::MoveTask() {
    DisplayTasks();

    size_t sourceProjectIndex;

    std::cout << "\t\t\tEnter the project number of the source column: ";
    std::cin >> sourceProjectIndex;

    if (sourceProjectIndex >= 1 && sourceProjectIndex <= MyProject.size()) {
        Project* sourceProject = MyProject[sourceProjectIndex - 1];

        size_t sourceColumnIndex, taskIndex;

        std::cout << "\t\t\tEnter the source column number (1: ToDo, 2: InProgress, 3: Completed): ";
        std::cin >> sourceColumnIndex;

        // Validate source column index
        if (sourceColumnIndex >= 1 && sourceColumnIndex <= 3) {
            std::cout << "\t\t\tEnter the task number to move: ";
            std::cin >> taskIndex;

            // Validate task index
            if (taskIndex >= 1) {
                switch (sourceColumnIndex) {
                case 1:
                    // Move task from ToDo to InProgress
                    sourceProject->myToDo.MoveTask(sourceProject->myInProgress, taskIndex - 1);
                    break;
                case 2:
                    // Move task from InProgress to Completed
                    sourceProject->myInProgress.MoveToCompleted(sourceProject->myCompleted, taskIndex - 1);
                    break;
                case 3:
                    std::cout << "Task is already in the Completed column.\n";
                    break;
                }
                std::cout << "Task moved successfully.\n";
            }
            else {
                std::cout << "Invalid task number. Task movement canceled.\n";
            }
        }
        else {
            std::cout << "Invalid source column number. Task movement canceled.\n";
        }
    }
    else {
        std::cout << "Invalid source project number. Task movement canceled.\n";
    }
}


