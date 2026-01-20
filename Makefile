CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = student_system
SRCS = main.cpp Student.cpp StudentManager.cpp GraduateStudent.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean pointer

# 专门用来跑指针练习的命令: make pointer
pointer: homework_pointer.cpp
	$(CXX) $(CXXFLAGS) -o pointer_lesson homework_pointer.cpp
	./pointer_lesson
