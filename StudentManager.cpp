#include "StudentManager.h"
#include "Student.h"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

void StudentManager::addStudent(const Student &student) {
  if (findStudentIndex(student.getId()) != -1) {
    std::cout << "Student with ID " << student.getId() << " already exists."
              << std::endl;
    return;
  }
  students.push_back(std::make_shared<Student>(student));
  std::cout << "Student added successfully." << std::endl;
}

void StudentManager::removeStudent(int id) {
  int index = findStudentIndex(id);
  if (index != -1) {
    students.erase(students.begin() + index);
    std::cout << "Student removed successfully." << std::endl;
  } else {
    std::cout << "Student not found." << std::endl;
  }
}

void StudentManager::listStudents() const {
  if (students.empty()) {
    std::cout << "No students found." << std::endl;
    return;
  }
  std::cout << "---------------------------------------------------"
            << std::endl;
  std::cout << "ID\tName\tAge\tGrade\tGender" << std::endl;
  std::cout << "---------------------------------------------------"
            << std::endl;
  for (const auto &student : students) {
    std::cout << student->getId() << "\t" << student->getName() << "\t"
              << student->getAge() << "\t" << student->getGrade() << "\t"
              << student->getGender() << std::endl;
  }
  std::cout << "---------------------------------------------------"
            << std::endl;
}

void StudentManager::searchStudent(int id) const {
  int index = findStudentIndex(id);
  if (index != -1) {
    const auto &student = students[index];
    std::cout << "Found Student: " << student->getName()
              << ", Age: " << student->getAge()
              << ", Grade: " << student->getGrade() << std::endl;
  } else {
    std::cout << "Student not found." << std::endl;
  }
}

void StudentManager::searchStudentName(std::string name) const {
  int index = findStudentByNameIndex(name);
  if (index != -1) {
    const auto &student = students[index];
    std::cout << "Found Student: " << student->getName()
              << ", Age: " << student->getAge()
              << ", Grade: " << student->getGrade() << std::endl;
  } else {
    std::cout << "Student not found." << std::endl;
  }
}

int StudentManager::findStudentIndex(int id) const {
  for (size_t i = 0; i < students.size(); ++i) {
    if (students[i]->getId() == id) {
      return i;
    }
  }
  return -1;
}

int StudentManager::findStudentByNameIndex(std::string name) const {
  for (size_t i = 0; i < students.size(); ++i) {
    if (students[i]->getName() == name) {
      return i;
    }
  }
  return -1;
}

void StudentManager::saveToFile(const std::string &filename) const {
  std::ofstream outFile(filename);
  if (outFile.is_open()) {
    for (const auto &student : students) {
      outFile << student->getId() << "," << student->getName() << ","
              << student->getAge() << "," << student->getGrade() << ","
              << student->getGender() << "\n";
    }
    outFile.close();
    std::cout << "Data saved to " << filename << std::endl;
  } else {
    std::cerr << "Unable to open file for writing." << std::endl;
  }
}

void StudentManager::loadFromFile(const std::string &filename) {
  std::ifstream inFile(filename);
  if (inFile.is_open()) {
    students.clear();
    std::string line;
    while (getline(inFile, line)) {
      size_t pos1 = line.find(',');
      size_t pos2 = line.find(',', pos1 + 1);
      size_t pos3 = line.find(',', pos2 + 1);
      size_t pos4 = line.find(',', pos3 + 1);

      if (pos1 != std::string::npos && pos2 != std::string::npos &&
          pos3 != std::string::npos) {
        int id = std::stoi(line.substr(0, pos1));
        std::string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        int age = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        double grade = std::stod(line.substr(pos3 + 1, pos4 - pos3 - 1));
        std::string gender = line.substr(pos4 + 1);
        students.push_back(std::make_shared<Student>(id, name, age, grade, gender));
      }
    }
    inFile.close();
    std::cout << "Data loaded from " << filename << std::endl;
  } else {
    std::cout << "No existing data file found. Starting fresh." << std::endl;
  }
}

void StudentManager::calcAvgMaxGrade() const {
  if (students.empty()) {
    std::cout << "还没有学生数据，无法统计。" << std::endl;
    return;
  }
  float sum = 0;
  float max = -1;
  for (size_t i = 0; i < students.size(); i++) {
    float cur = students[i]->getGrade();
    sum += cur;
    if (cur > max) {
      max = cur;
    }
  }
  std::cout << "平均数是： " << sum / students.size() << std::endl;
  std::cout << "最大值是： " << max << std::endl;
}

void StudentManager::sortStudentsByGrade() {
  std::sort(students.begin(), students.end(),
            [](const std::shared_ptr<Student> a, const std::shared_ptr<Student> b) {
              // C++ sort 需要返回 bool (true/false)，而不是数字
              // return true 表示 a 应该排在 b 前面
              return a->getGrade() > b->getGrade(); // 降序：大的在前
            });
  std::cout << "已经排序完成 (按成绩从高到低) ，新的数组是: " << std::endl;
  listStudents();
}

// Homework 7: 请在这里实现 getTopStudent
// 提示：
// 1. 如果 students 是空的，直接返回 nullptr
// 2. 准备一个指针 const Student* best = &students[0];
// 3. 遍历数组，如果发现谁的 grade 更高，就让 best 指向谁 (best = &students[i])
// 4. 最后返回 best
const std::shared_ptr<Student> StudentManager::getTopStudent() const {
  if (students.size() == 0)
    return nullptr;

  std::shared_ptr<Student> best = students[0];
  for (size_t i = 0; i < students.size(); i++) {
    if (students[i]->getGrade() > best->getGrade()) {
      best = students[i];
    }
  }

  // for (const Student& stu : students) {

  // }
  return best;
}

// Homework 8: 统计男女生平均分
// 提示：
// 1. 准备四个变量：maleCount, maleTotalGrade, femaleCount, femaleTotalGrade
// 2. 遍历 students 数组
// 3. 检查每个学生的 gender (用 getGender() == "男" 或 "Male")
// 4. 分别累加分数和人数
// 5. 最后算除法 (记得防除以 0 哦)
std::map<std::string, float> StudentManager::showGenderStatistics() const {
  // 请在这里开始您的表演
  int maleCount = 0, femaleCount = 0;
  float maleTotalGrade = 0.0, femaleTotalGrade = 0.0;
  for (auto p1 : students) {
    if (p1->getGender() == "男") {
      maleCount++;
      maleTotalGrade += p1->getGrade();
    } else {
      femaleCount++;
      femaleTotalGrade += p1->getGrade();
    }
  }

  std::map<std::string, float> result;
  result["male"] = (maleCount > 0 ? maleTotalGrade / maleCount : 0);
  result["female"] = (femaleCount > 0 ? femaleTotalGrade / femaleCount : 0);
  return result;
}
