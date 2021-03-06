#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};



// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;


TaskStatus Next(TaskStatus task_status) {
  return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

void RemoveZeros(TasksInfo& tasks_info) {
  vector<TaskStatus> statuses_to_remove;
  for (const auto& task_item : tasks_info) {
    if (task_item.second == 0) {
      statuses_to_remove.push_back(task_item.first);
    }
  }
  for (const TaskStatus status : statuses_to_remove) {
    tasks_info.erase(status);
  }
}

class TeamTasks {
private:
  map<string, TasksInfo> personTasks;
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const{
    return personTasks.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person){
    personTasks[person][TaskStatus::NEW] ++;
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
    TasksInfo updated_tasks, untouched_tasks;
    TasksInfo& tasks = personTasks[person];

    for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
      updated_tasks[Next(status)] = min(task_count, tasks[status]);
      task_count -= updated_tasks[Next(status)];
    }

    for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
      untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
      tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
    }
    RemoveZeros(updated_tasks);
    RemoveZeros(untouched_tasks);
    RemoveZeros(personTasks.at(person));

    return{updated_tasks, untouched_tasks};
  }
};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
