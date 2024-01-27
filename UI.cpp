#include "UI.h"
#include "MainScreen.h"
#include "Login.h"

// Function to clear the console screen
void UI::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to display the project management menu
void UI::displayProjectMenu() {
    std::cout << "\n";
    std::cout << "\t\t\t---------------------\n";
    std::cout << "\t\t\t[1] Create Project\n";
    std::cout << "\t\t\t[2] Delete Project\n";
    std::cout << "\t\t\t[3] Create Task\n";
    std::cout << "\t\t\t[4] Display Tasks\n";
    std::cout << "\t\t\t[5] Move Task\n";
    std::cout << "\t\t\t[6] Back to Main Menu\n";
    std::cout << "\t\t\t---------------------\n";
    std::cout << "\t\t\tEnter your choice: ";
}

// Function to prompt the user to press Enter to continue
void UI::pressEnterToContinue() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Wait for user input before continuing
}

void UI::Open() {
    MainScreen mainScreen;
    bool isLoggedIn = false;

    while (true) {
        clearScreen(); // Clear the console screen

        int choice;

        // Display the main menu
        std::cout << "------------------\n";
        std::cout << "[1] Register\n";
        std::cout << "[2] Login\n";
        std::cout << "[3] Display users\n";
        std::cout << "[4] Manage Projects\n";
        std::cout << "[5] Exit\n";
        std::cout << "------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            Register::registerUser();
            pressEnterToContinue();
            break;
        case 2:
            Login::performLogin();
            isLoggedIn = true;
            pressEnterToContinue();
            break;
        case 3:
            Register::displayUsers();
            pressEnterToContinue();
            break;
        case 4:
            if (isLoggedIn) {
                int projectChoice = 0;

                while (projectChoice != 8) {
                    // Display the project management menu
                    displayProjectMenu();
                    std::cin >> projectChoice;

                    switch (projectChoice) {
                    case 1:
                        mainScreen.CreateProject();
                        break;
                    case 2:
                        mainScreen.DeleteProject();
                        break;
                    case 3:
                        mainScreen.CreateTask();
                        break;
                    case 4:
                        mainScreen.DisplayTasks();
                        break;
                    case 5:
                        mainScreen.MoveTask();
                        break;
                    case 6:
                        // Back to the main menu
                        std::cout << "Returning to the main menu...\n";
                        break;
                    default:
                        std::cout << "Invalid choice\n";
                    }
                }
            }
            else {
                std::cout << "Please log in first.\n";
            }
            pressEnterToContinue();
            break;
        case 5:
            std::cout << "Exiting...\n";
            return; // Exit the program
        default:
            std::cout << "Invalid choice\n";
            return;
        }
    }
}
