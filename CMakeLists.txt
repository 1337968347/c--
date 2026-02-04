cmake_minimum_required(VERSION 3.10)
project(StudentSystem)

# 设置 C++ 标准为 C++11 (和之前的 Makefile 一样)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. 主程序 (学生管理系统)
# 对应 Makefile 里的: TARGET = student_system
add_executable(student_system 
    main.cpp 
    Student.cpp 
    StudentManager.cpp 
    GraduateStudent.cpp
)

# 2. 指针练习
# 对应 Makefile 里的: pointer
add_executable(pointer_test homework_pointer.cpp)

# 3. 内存管理练习
# 对应 Makefile 里的: memory
add_executable(memory_test homework_memory.cpp)

# 4. 链表练习
# 对应 Makefile 里的: linkedlist
add_executable(linkedlist_test homework_linkedlist.cpp)

# 5. 菜谱练习 (No.23)
# 对应 Makefile 里的: recipes
add_executable(recipes_test homework_recipes.cpp)

# 6. 超市练习 (No.24)
# 对应 Makefile 里的: supermarket
add_executable(supermarket_test homework_supermarket.cpp)

# 7. 代码分家练习 (No.25)
# 对应 Makefile 里的: split
# 注意：这里需要包含 SimpleMath.cpp
add_executable(split_test 
    homework_split.cpp 
    SimpleMath.cpp
)

# 这一行是为了方便在 IDE 里能看到所有源文件
file(GLOB_RECURSE ALL_SOURCES "*.cpp" "*.h")
