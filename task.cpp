#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a simple task structure
struct Task {
  string description;
  bool completed;
};

// Define the to-do list manager class
class ToDoList {
public:
  // Add a new task
  void add_task(const string& description) {
    Task new_task;
    new_task.description = description;
    new_task.completed = false;
    tasks.push_back(new_task);
    cout << "Task added successfully!" << endl;
  }

  // View all tasks
  void view_tasks() const {
    if (tasks.empty()) {
      cout << "There are no tasks in the list." << endl;
      return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
      string status = tasks[i].completed ? "Completed" : "Pending";
      cout << "- [" << i + 1 << "] " << status << ": " << tasks[i].description << endl;
    }
  }

  // Delete a task by index
  void delete_task(int index) {
    if (index < 0 || index >= static_cast<int>(tasks.size())) {
      cout << "Invalid task index!" << endl;
      return;
    }

    tasks.erase(tasks.begin() + index);
    cout << "Task deleted successfully!" << endl;
  }

private:
  vector<Task> tasks;
};

int main() {
  ToDoList todo_list;

  while (true) {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";

    int choice;
    cin >> choice;

    switch (choice) {
      case 1: {
        string description;
        cout << "Enter task description: ";
        cin.ignore(); // Consume newline character
        getline(cin, description);
        todo_list.add_task(description);
        break;
      }
      case 2:
        todo_list.view_tasks();
        break;
      case 3: {
        todo_list.view_tasks();
        cout << "Enter the index of the task to delete: ";
        int index;
        cin >> index;
        todo_list.delete_task(index - 1);
        break;
      }
      case 4:
        cout << "Exiting..." << endl;
        return 0;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  }
}
