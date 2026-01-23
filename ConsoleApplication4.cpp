#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    struct Task
    {
        int id;
        string nameTask;
        bool done;
    };
    vector<Task> tasks;
    while (true)
    {
       
        int answer;
        int count = 0;
        bool status = false;
        cout << "1. Добавить задачу\n2. Список задач\n3. Удалить задачу\nВыбирите действие:" << endl;
        cin >> answer;

        if (answer == 1)
        {
            Task task_1;
            cout << "Введите название задачи" << endl;
            cin >> task_1.nameTask;
            task_1.id = count++;
            task_1.done = status;
            tasks.push_back(task_1);
        }
        else if (answer == 2)
        {
            for (int i = 0; i < tasks.size(); i++)
            {
                cout << "Название: " << tasks[i].nameTask << endl;
                cout << "ID: " << tasks[i].id << endl;
                cout << "Статус: " << tasks[i].done << endl;
            }
        }
        else
        {
            break;
        }
    }
    
    return 0;
}
