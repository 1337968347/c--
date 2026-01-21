#include "GraduateStudent.h"
#include "Student.h"
#include "StudentManager.h"
#include <chrono>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <thread>

void printMenu() {
  std::cout << "\n=== Student Management System ===" << std::endl;
  std::cout << "1. 添加学生" << std::endl;
  std::cout << "2. 删除学生" << std::endl;
  std::cout << "3. 显示所有学生" << std::endl;
  std::cout << "4. 搜索学生" << std::endl;
  std::cout << "5. 保存数据" << std::endl;
  std::cout << "6. 加载数据" << std::endl;
  std::cout << "7. 计算平均成绩" << std::endl;
  std::cout << "8. 按照学习成绩排序" << std::endl;
  std::cout << "9. 查找状元" << std::endl;
  std::cout << "10. 统计男女平均分" << std::endl;
  std::cout << "0. 退出" << std::endl;
  std::cout << "请输入您的选择: ";
}

void autoSave(const StudentManager *manager) {
  while (true) {
    std::cout << "[AutoBackup] Data start." << std::endl;

    // 自动保存功能占位，后续可扩展定时保存逻辑
    std::this_thread::sleep_for(std::chrono::seconds(5));
    manager->saveToFile("students.txt");
    std::cout << "[AutoBackup] Data saved." << std::endl;
  }
}

template <typename T> void printEvenyThing(const T someThing) {
  std::cout << "万能打印: " << someThing << std::endl;
}

int main() {
  //   Student s1(1, "测试1", 11, 12, "123");
  //   Student s2 = s1;
  //   Student s3 = std::move(s1);
  //   s1.getName();

  StudentManager manager;
  //   const std::string filename = "students.txt";
  std::thread t(autoSave, &manager);
  t.detach();

  std::this_thread::sleep_for(std::chrono::seconds(100));

  //   // Auto load on startup
  //   manager.loadFromFile(filename);
  //   // try{

  //   //     Student s1(1, "测试1", -1, 12, "123");
  //   //     Student s2(1, "测试2", 11, 12, "123");
  //   //     GraduateStudent s3(1, "测试2", 11, 12, "123", "搬砖");
  //   //     s3.display();

  //   // } catch (const std::exception& e) {
  //   //   std::cerr << "捕获到错误: " << e.what() << std::endl;
  //   // }

  //   int choice;
  //   while (true) {
  //     printMenu();
  //     if (!(std::cin >> choice)) {
  //       std::cin.clear();
  //       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  //       std::cout << "Invalid input. Please enter a number." << std::endl;
  //       continue;
  //     }

  //     if (choice == 0) {
  //       std::cout << "Exiting..." << std::endl;
  //       break;
  //     }

  //     switch (choice) {
  //     case 1: {
  //       int id, age;
  //       std::string name;
  //       double grade;
  //       std::string gender;

  //       std::cout << "Enter ID: ";
  //       std::cin >> id;
  //       std::cout << "Enter Name: ";
  //       std::cin >> name; // Note: simple cin >> name reads until space. For
  //       full
  //                         // names use getline.
  //       std::cout << "Enter Age:";
  //       std::cin >> age;
  //       while (true) {
  //         std::cout << "请输入年级: 0-100: ";
  //         std::cin >> grade;
  //         if (grade >= 0 && grade <= 100) {
  //           break;
  //         }
  //       }
  //       std::cout << "Enter Gender: ";
  //       std::cin >> gender;

  //       manager.addStudent(Student(id, name, age, grade, gender));
  //       break;
  //     }
  //     case 2: {
  //       int id;
  //       std::cout << "Enter ID to remove: ";
  //       std::cin >> id;
  //       manager.removeStudent(id);
  //       break;
  //     }
  //     case 3:
  //       manager.listStudents();
  //       break;
  //     case 4: {
  //       // int id;
  //       // std::cout << "Enter ID to search: ";
  //       // std::cin >> id;
  //       // manager.searchStudent(id);
  //       std::string name;
  //       std::cout << "Enter Name to Search: ";
  //       std::cin >> name;
  //       manager.searchStudentName(name);
  //       break;
  //     }
  //     case 5:
  //       manager.saveToFile(filename);
  //       break;
  //     case 6:
  //       manager.loadFromFile(filename);
  //       break;
  //     case 7:
  //       manager.calcAvgMaxGrade();
  //       break;
  //     case 8:
  //       manager.sortStudentsByGrade();
  //       break;
  //     case 9: {
  //       const std::shared_ptr<Student> top = manager.getTopStudent();
  //       if (top != nullptr) {
  //         // 指针访问成员要用箭头 ->
  //         std::cout << "状元是: " << top->getName()
  //                   << " (成绩: " << top->getGrade() << ")" << std::endl;
  //       } else {
  //         std::cout << "班里还没人呢！" << std::endl;
  //       }
  //       break;
  //     }
  //     case 10: {
  //       std::map<std::string, float> result = manager.showGenderStatistics();
  //       for (const auto &item : result) {
  //         std::cout << item.first << ": " << item.second << std::endl;
  //       }
  //       break;
  //     }
  //     default:
  //       std::cout << "Invalid choice. Try again." << std::endl;
  //     }
  //   }

  // std::cout << (s1 == s2) << std::endl;
  // printEvenyThing(100);
  // printEvenyThing("Hello C++");
  // printEvenyThing(3.14159);
  return 0;
}
