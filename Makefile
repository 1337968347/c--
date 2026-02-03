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

.PHONY: all clean pointer memory linkedlist recipes supermarket split

# 专门用来跑指针练习的命令: make pointer
pointer: homework_pointer.cpp
	$(CXX) $(CXXFLAGS) homework_pointer.cpp -o pointer_test
	./pointer_test

memory: homework_memory.cpp
	$(CXX) $(CXXFLAGS) homework_memory.cpp -o memory_test
	./memory_test

linkedlist: homework_linkedlist.cpp
	$(CXX) $(CXXFLAGS) homework_linkedlist.cpp -o linkedlist_test
	./linkedlist_test

recipes: homework_recipes.cpp
	$(CXX) $(CXXFLAGS) homework_recipes.cpp -o recipes_test
	./recipes_test

supermarket: homework_supermarket.cpp
	$(CXX) $(CXXFLAGS) homework_supermarket.cpp -o supermarket_test
	./supermarket_test

split: homework_split.cpp SimpleMath.cpp
	$(CXX) $(CXXFLAGS) homework_split.cpp SimpleMath.cpp -o split_test
	./split_test
