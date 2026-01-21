#include "GraduateStudent.h"
#include <sstream>
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

  std::string GraduateStudent::serialize() const {
    std::stringstream ss;
    ss <<"ID: " << "ID: " << getId() 
              << ", Name: " << getName() 
              << ", Age: " << getAge() 
              << ", Grade: " << getGrade() 
              << ", Gender: " << getGender() 
              << ", SearchTopic: " << searchTopic;
              
    return ss.str();
  }