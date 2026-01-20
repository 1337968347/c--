#include "GraduateStudent.h"
#include <string>

  std::string GraduateStudent::researchTopic() const { return searchTopic; };

  void GraduateStudent::display() const {
      std::cout << "ID: " << getId() 
              << ", Name: " << getName() 
              << ", Age: " << getAge() 
              << ", Grade: " << getGrade() 
              << ", Gender: " << getGender() 
              << ", SearchTopic: " << searchTopic << std::endl;
  }