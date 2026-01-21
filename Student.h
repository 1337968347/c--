#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    Student(int id, std::string name, int age, double grade, std::string gender);
    Student(const Student& other);
    Student(const Student&& other);

    int getId() const;
    std::string getName() const;
    int getAge() const;
    double getGrade() const;

    bool operator==(const Student& student) const;
    
    std::string getGender() const;
    virtual void display() const;
    virtual std::string serialize() const ;
    
    virtual ~Student(){};


private:
    int id;
    std::string name;
    int age;
    double grade;
    std::string gender;
};

#endif // STUDENT_H
