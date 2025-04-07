#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>

struct Task {
    int id;
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::list<Task> tasks;
    int nextId;

public:
    ToDoList() : nextId(1) {
        loadFromFile();
    }

    void addTask(const std::string& desc) {
        tasks.push_back({nextId++, desc, false});
        std::cout << " Tarea agregada.\n";
        saveToFile();
    }

    void completeTask(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.completed = true;
                std::cout << " Tarea completada.\n";
                saveToFile();
                return;
            }
        }
        std::cout << " Tarea no encontrada.\n";
    }

    void deleteTask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                std::cout << "🗑️ Tarea eliminada.\n";
                saveToFile();
                return;
            }
        }
        std::cout << "Tarea no encontrada.\n";
    }

    void showTasks() const {
        if (tasks.empty()) {
            std::cout << "📭 No hay tareas.\n";
            return;
        }

        for (const auto& task : tasks) {
            std::cout << "[" << task.id << "] "
                      << (task.completed ? "[✔️] " : "[ ] ")
                      << task.description << "\n";
        }
    }

    void loadFromFile() {
        std::ifstream file("tareas.txt");
        if (!file.is_open()) return;

        Task t;
        tasks.clear();
        while (file >> t.id) {
            file.ignore();
            std::getline(file, t.description, '|');
            file >> t.completed;
            file.ignore();
            tasks.push_back(t);
            if (t.id >= nextId) nextId = t.id + 1;
        }
        file.close();
    }

    void saveToFile() {
        std::ofstream file("tareas.txt");
        for (const auto& t : tasks) {
            file << t.id << " " << t.description << "|" << t.completed << "\n";
        }
        file.close();
    }
};

#endif

