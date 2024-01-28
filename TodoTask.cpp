#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markTaskAsCompleted(vector<Task> &tasks, int index);
void removeTask(vector<Task> &tasks, int index);

int main() {
    vector<Task> tasks;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter the task description: ";
                cin.ignore();  // Ignore the newline character in the buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markTaskAsCompleted(tasks, index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                cout << "Exiting the to-do list manager." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n==== To-Do List Manager ====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<Task> &tasks, const string &description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
    cout << "\n==== Task List ====" << endl;
    cout << setw(4) << "Index" << setw(25) << "Description" << setw(15) << "Status" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << setw(4) << i << setw(25) << tasks[i].description << setw(15) << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markTaskAsCompleted(vector<Task> &tasks, int index) {
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        tasks[index].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid index. No task found." << endl;
    }
}

void removeTask(vector<Task> &tasks, int index) {
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid index. No task found." << endl;
    }
}
