# C++ 学习小作业

这里记录奶奶的 C++ 学习进度和完成情况。

## 1. 界面汉化与美化
- [x] **作业内容**：把英文菜单改成中文，让它看起来更亲切。
- [x] **状态**：已完成

## 2. 输入校验 (表单验证)
- [x] **作业内容**：防止用户输入错误的年级（比如 -100 或 200）。如果输入不对，就一直让他重输，直到正确为止。
- [x] **状态**：已完成

## 3. 按名字搜索
- [x] **作业内容**：实现 `searchStudentName` 函数，让用户可以通过输入名字找到学生。
- [x] **状态**：已完成

## 4. 班级成绩统计
- [x] **作业内容**：实现 `showStatistics` 函数，计算全班的**平均分**，并找出**最高分**是谁。
- [x] **状态**：已完成

## 5. 成绩光荣榜 (排序)
- [x] **作业内容**：实现 `sortStudentsByGrade` 函数，把学生按照成绩从高到低排列。
- [x] **状态**：已完成

## 6. 指针初体验 (Pointer)
- [x] **作业内容**：打开 `homework_pointer.cpp`，按照里面的中文提示，补全 4 行代码。学会怎么用“遥控器”控制变量。
- [x] **运行方法**：在终端输入 `make pointer`
- [x] **状态**：已完成

## 7. 谁是状元？(指针实战)
- [x] **作业内容**：
    1. 在 `StudentManager.cpp` 里找到 `getTopStudent` 函数。
    2. 实现它：遍历学生，返回指向分数最高那个学生的**指针**。
    3. 在 `main.cpp` 里加一个菜单选项 "9. 查找状元"，调用这个函数。
    4. **注意**：如果返回的不是 `nullptr`，记得用 `->` 把他的名字打印出来！
- [x] **状态**：已完成

## 8. 男女生大比拼 (数据统计)
- [x] **作业内容**：
    1. 在 `StudentManager.cpp` 里实现 `showGenderStatistics` 函数。
    2. 统计男生的平均分、女生的平均分。
    3. 别忘了在 `main.cpp` 里加个菜单 "10. 性别统计"。
    4. **挑战**：看看男生厉害还是女生厉害？
- [x] **状态**：已完成

## 9. 代码现代化改造 (C++11 新语法)
- [x] **作业内容**：
    1. 学习 `auto` 关键字：让编译器自己猜变量类型。
    2. 学习 `Range-based for loop` (范围循环)：像 JS 的 `for...of` 一样遍历数组。
    3. **任务**：修改 `showGenderStatistics` 函数，把老式的 `for (size_t i = 0...)` 循环改成新式的 `for (const auto& student : students)`。
- [x] **状态**：已完成

## 10. 函数返回值改造 (std::map)
- [x] **作业内容**：
    1. 引入 `<map>` 头文件。
    2. 修改 `showGenderStatistics`，让它不再直接打印，而是返回一个 `std::map<std::string, double>`。
    3. 这个 Map 就相当于 JS 里的对象：`{ "男": 80.5, "女": 90.0 }`。
    4. 在 `main.cpp` 里接收这个返回值，并打印出来。
- [x] **状态**：已完成

## 11. 运算符重载 (Operator Overloading)
- [x] **作业内容**：
    1. **概念**：在 JS 里，`+` 号只能加数字或拼接字符串。在 C++ 里，我们可以让 `Student` 对象也能“相加”！
    2. **目标**：实现 `Student` 的 `==` 运算符，判断两个学生是不是同一个人（ID 相同）。
    3. **任务**：
        - 在 `Student.h` 里声明 `bool operator==(const Student& other) const;`
        - 在 `Student.cpp` 里实现它：如果 `this->id` 等于 `other.id`，就返回 true。
        - 在 `main.cpp` 里测试一下：创建两个 ID 一样的学生，看看 `s1 == s2` 是否为真。
- [x] **状态**：已完成

## 12. 泛型编程初体验 (Templates)
- [ ] **作业内容**：
    1. **概念**：在 JS 里，函数参数随便传什么类型都行。在 C++ 里，我们可以用**模板 (Template)** 来实现类似的效果。这叫“泛型编程”。
    2. **目标**：写一个“万能打印函数” `printAnything`，不管传 `int`、`double` 还是 `string` 给它，它都能打印出来。
    3. **任务**：
        - 在 `main.cpp` 的最上面（`main` 函数外面），定义一个模板函数：
          ```cpp
          template <typename T>
          void printAnything(T value) {
              std::cout << "万能打印: " << value << std::endl;
          }
          ```
        - 在 `main` 函数里试着调用它：
          - `printAnything(100);`
          - `printAnything("Hello C++");`
          - `printAnything(3.14159);`
- [ ] **状态**：待完成
