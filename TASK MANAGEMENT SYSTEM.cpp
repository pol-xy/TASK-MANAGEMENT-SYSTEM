// BERANA, JON PAUL S.   CS-1102
// FINAL PROJECT IN COMPUTER PROGRAMMING 
// TASK MANAGEMENT SYSTEM

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_TASKS = 100;

// Task structure
struct Task {
    string name;
    string deadline;
    string status; // "Pending" or "Completed"
};

Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask();
void viewTasks();
void updateTask();
void deleteTask();
void menu();

int main() {
    menu();
    return 0;
}

// Menu function
void menu() {
    int choice;
    do {
        cout << "\n====================================\n";
        cout << "       Task Management System       \n";
        cout << "====================================\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Update Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: updateTask(); break;
            case 4: deleteTask(); break;
            case 5: cout << "\nExiting the program... Thank you!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

// Add a new task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "\nTask list is full!\n";
        return;
    }
    Task newTask;
    cin.ignore();
    cout << "\nEnter task name: ";
    getline(cin, newTask.name);
    cout << "Enter deadline (e.g., YYYY-MM-DD): ";
    getline(cin, newTask.deadline);
    cout << "Enter status (Pending/Completed): ";
    getline(cin, newTask.status);

    tasks[taskCount++] = newTask;
    cout << "\nTask added successfully!\n";
}

// View all tasks
void viewTasks() {
    if (taskCount == 0) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n====================================\n";
    cout << setw(5) << "No." << setw(20) << "Task Name" << setw(15) << "Deadline" << setw(15) << "Status" << "\n";
    cout << "------------------------------------\n";

    for (int i = 0; i < taskCount; ++i) {
        cout << setw(5) << i + 1 
             << setw(20) << tasks[i].name 
             << setw(15) << tasks[i].deadline 
             << setw(15) << tasks[i].status << "\n";
    }

    cout << "====================================\n";
}

// Update a task
void updateTask() {
    if (taskCount == 0) {
        cout << "\nNo tasks available to update.\n";
        return;
    }
    int taskNumber;
    viewTasks();
    cout << "\nEnter the task number to update: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }
    Task &task = tasks[taskNumber - 1];
    cin.ignore(); 
    cout << "\nUpdating task: " << task.name << "\n";
    cout << "Enter new name (or press Enter to keep current): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) task.name = newName;

    cout << "Enter new deadline (or press Enter to keep current): ";
    string newDeadline;
    getline(cin, newDeadline);
    if (!newDeadline.empty()) task.deadline = newDeadline;

    cout << "Enter new status (Pending/Completed): ";
    string newStatus;
    getline(cin, newStatus);
    if (!newStatus.empty()) task.status = newStatus;

    cout << "\nTask updated successfully!\n";
}

// Delete a task
void deleteTask() {
    if (taskCount == 0) {
        cout << "\nNo tasks available to delete.\n";
        return;
    }
    int taskNumber;
    viewTasks();
    cout << "\nEnter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }
    for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }
    --taskCount;
    cout << "\nTask deleted successfully!\n";
}
