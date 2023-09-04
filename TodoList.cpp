#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Task
{
public:
    string name;
    string due_date;
    string priority;
    bool completed;
    Task(const string &n, const string &dd, const string &p)
        : name(n), due_date(dd), priority(p), completed(false) {}
};
class ToDoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const Task &task)
    {
        tasks.push_back(task);
    }
    void showTask()
    {
        if (tasks.empty())
        {
            cout << "No tasks to display.";
        }
        else
        {
            for (int i = 0; i < tasks.size(); i++)
            {
                const Task &task = tasks[i];
                string status = task.completed ? "completed" : "Not Completed";
                cout << i + 1 << "." << task.name << "- Due: " << task.due_date << " - Priority: " << task.priority << " - Status: " << status << endl;
            }
        }
    }

    void Markcompleted(int taskindex)
    {
        if (taskindex >= 0 && taskindex < tasks.size())
        {
            tasks[taskindex].completed = true;
            cout << "Task marked as completed" << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int taskindex)
    {
        if (taskindex >= 0 && taskindex < tasks.size())
        {
            Task removedTask = tasks[taskindex];
            tasks.erase(tasks.begin() + taskindex);
            cout << "Removed task: " << removedTask.name << std::endl;
        }
        else
        {
            cout << "Invalid task index." << std::endl;
        }
    }
};
int main()
{
    ToDoList obj;

    while (true)
    {
        cout << "\n---To-Do List---" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Mark Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            string name, due_date, priority;
            cout << "Task name: ";
            getline(cin, name);
            cout << "Due date: ";
            cin >> due_date;
            cout << "Priority: ";
            cin >> priority;
            Task task(name, due_date, priority);
            obj.addTask(task);
            break;
        }
        case 2:
            obj.showTask();
            break;

        case 3:
            int taskindex;
            cout << "Enter the task index to mark as completed: ";
            cin >> taskindex;
            obj.Markcompleted(taskindex - 1);
            break;
        case 4:

            cout << "Enter the task index to remove: ";
            cin >> taskindex;
            obj.removeTask(taskindex - 1);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invaild choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}