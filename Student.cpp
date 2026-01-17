#include "Student.h"

Student::Student(int id, std::string name, int age, double grade, std::string gender)
    : id(id), name(name), age(age), grade(grade), gender(gender) {}

int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

double Student::getGrade() const {
    return grade;
}

std::string Student::getGender() const {
    return gender;
}

void Student::display() const {
    std::cout << "ID: " << id 
              << ", Name: " << name 
              << ", Age: " << age 
              << ", Grade: " << grade 
              << ", Gender: " << gender << std::endl;
}
