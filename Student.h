#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    Student(int id, std::string name, int age, double grade, std::string gender);
    
    int getId() const;
    std::string getName() const;
    int getAge() const;
    double getGrade() const;

    virtual void display() const;
    bool operator==(const Student& student) const;

    std::string getGender() const;

    virtual ~Student(){};


private:
    int id;
    std::string name;
    int age;
    double grade;
    std::string gender;
};

#endif // STUDENT_H
