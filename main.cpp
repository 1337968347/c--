#include <iostream>
#include <limits>
#include "StudentManager.h"

void printMenu() {
    std::cout << "\n=== Student Management System ===" << std::endl;
    std::cout << "1. 添加学生" << std::endl;
    std::cout << "2. 删除学生" << std::endl;
    std::cout << "3. 显示所有学生" << std::endl;
    std::cout << "4. 搜索学生" << std::endl;
    std::cout << "5. 保存数据" << std::endl;
    std::cout << "6. 加载数据" << std::endl;
    std::cout << "0. 退出" << std::endl;
    std::cout << "请输入您的选择: ";
}

int main() {
    StudentManager manager;
    const std::string filename = "students.txt";
    
    // Auto load on startup
    manager.loadFromFile(filename);

    int choice;
    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        if (choice == 0) {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                int id, age;
                std::string name;
                double grade;
                std::string gender;

                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std::cin >> name; // Note: simple cin >> name reads until space. For full names use getline.
                std::cout << "Enter Age: ";
                std::cin >> age;
                while ( true ) {
                    std::cout << "请输入年级: 0-100: ";
                    std::cin >> grade;
                    if(grade >= 0 && grade <= 100){
                        break;
                    }
                }
                std::cout << "Enter Gender: ";
                std::cin >> gender;
                
                manager.addStudent(Student(id, name, age, grade, gender));
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter ID to remove: ";
                std::cin >> id;
                manager.removeStudent(id);
                break;
            }
            case 3:
                manager.listStudents();
                break;
            case 4: {
                // int id;
                // std::cout << "Enter ID to search: ";
                // std::cin >> id;
                // manager.searchStudent(id);
                std::string name;
                std::cout << "Enter Name to Search: ";
                std::cin >> name;
                manager.searchStudentName(name);
                break;
            }
            case 5:
                manager.saveToFile(filename);
                break;
            case 6:
                manager.loadFromFile(filename);
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
