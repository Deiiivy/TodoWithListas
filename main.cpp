#include "ToDoList.h"

int main() {
    ToDoList list;
    int option;
    std::string desc;
    int id;

    do {
        std::cout << "\n==== To-Do List ====\n";
        std::cout << "1. Agregar tarea\n";
        std::cout << "2. Completar tarea\n";
        std::cout << "3. Eliminar tarea\n";
        std::cout << "4. Ver tareas\n";
        std::cout << "0. Salir\n";
        std::cout << "Opción: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1:
                std::cout << "Descripción: ";
                std::getline(std::cin, desc);
                list.addTask(desc);
                break;
            case 2:
                std::cout << "ID de tarea: ";
                std::cin >> id;
                list.completeTask(id);
                break;
            case 3:
                std::cout << "ID de tarea: ";
                std::cin >> id;
                list.deleteTask(id);
                break;
            case 4:
                list.showTasks();
                break;
            case 0:
                std::cout << " Hasta luego.\n";
                break;
            default:
                std::cout << " Opción inválida.\n";
        }

    } while (option != 0);

    return 0;
}

