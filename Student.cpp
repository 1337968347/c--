#include "Student.h"
#include <sstream>
#include <stdexcept>
#include <string>

Student::Student(int id, std::string name, int age, double grade,
                 std::string gender)
    : id(id), name(name), age(age), grade(grade), gender(gender) {
  if (age < 0) {
    throw std::runtime_error("age 过于小了");
  }
}

Student::Student(const Student &other)
    : id(other.id), name(other.name), age(other.age), grade(other.grade),
      gender(other.gender) {
  std::cout << "Copy" << std::endl;
}

Student::Student(const Student &&other)
    : id(other.id), name(std::move(other.name)), age(other.age),
      grade(std::move(other.grade)) {
  std::cout << "Move" << std::endl;
}

int Student::getId() const { return id; }

std::string Student::getName() const { return name; }

int Student::getAge() const { return age; }

double Student::getGrade() const { return grade; }

bool Student::operator==(const Student &other) const {
  return other.id == this->id;
}

std::string Student::getGender() const { return gender; }

std::string Student::serialize() const {
  std::stringstream ss;
  ss << "ID: " << id << ", Name: " << name << ", Age: " << age
     << ", Grade: " << grade << ", Gender: " << gender;
  return ss.str();
}
void Student::display() const {
  std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age
            << ", Grade: " << grade << ", Gender: " << gender << std::endl;
}
