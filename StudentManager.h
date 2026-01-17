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
  void calcAvgGrade() const;

private:
  std::vector<Student> students;
  int findStudentIndex(int id) const;
  int findStudentByNameIndex(std::string name) const;
};

#endif // STUDENTMANAGER_H
