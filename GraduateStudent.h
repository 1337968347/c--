#ifndef Gradute_Student
#define Gradute_Student

#include "Student.h"
#include <string>

class GraduateStudent : public Student {
public:
  GraduateStudent(int id, std::string name, int age, double grade,
                 std::string gender, std::string searchTopic)
      : Student(id, name, age, grade, gender), searchTopic(searchTopic) {}

  std::string searchTopic;

  void display() const;

  std::string researchTopic() const;
};

#endif // Gradute_Student_H