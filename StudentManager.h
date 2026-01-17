#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <string>
#include <vector>

class StudentManager {
public:
  void addStudent(const Student &student);
  void removeStudent(int id);
  void listStudents() const;
  void searchStudent(int id) const;
  void searchStudentName(std::string name) const;

  // File operations
  void saveToFile(const std::string &filename) const;
  void loadFromFile(const std::string &filename);
  void calcAvgMaxGrade() const;
  void sortStudentsByGrade();
  
  // Homework 7: 返回指向最高分学生的指针 (如果没有学生返回 nullptr)
  const Student* getTopStudent() const;


private:
  std::vector<Student> students;
  int findStudentIndex(int id) const;
  int findStudentByNameIndex(std::string name) const;
};

#endif // STUDENTMANAGER_H
