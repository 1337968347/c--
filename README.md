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
- [x] **作业内容**：
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
- [x] **状态**：已完成

## 13. 继承与多态 (Inheritance & Polymorphism)
- [x] **作业内容**：
    1. **概念**：
        - **继承**：就像 JS 里的 `class Graduate extends Student`，研究生也是学生，但有自己的特殊属性。
        - **虚函数 (virtual)**：在 C++ 里，如果你想让子类覆盖父类的方法（Override），父类必须允许（加上 `virtual` 关键字）。JS 里默认都能覆盖，C++ 默认不行。
    2. **目标**：创建一个 `GraduateStudent` (研究生) 类，继承自 `Student`。
- [x] **状态**：已完成

## 14. 异常处理 (Exception Handling)
- [x] **作业内容**：
    1. **概念**：JS 里有 `try...catch`，C++ 也有！当程序出错时（比如输入年龄 -100），我们不应该让它直接崩溃，而是要“抛出异常”并“捕获处理”。
    2. **目标**：给 `Student` 类的构造函数加个保险。如果输入的 `age` 小于 0 或大于 150，就报错。
    3. **任务**：
        - 修改 `Student.cpp`：在构造函数里检查 `age`。如果 `age < 0`，用 `throw std::runtime_error("年龄不对！");` 扔出一个错误。
        - 修改 `main.cpp`：用 `try { ... } catch (const std::exception& e) { ... }` 包裹创建学生代码。
- [x] **状态**：已完成

## 15. 智能指针 (Smart Pointers) - 拒绝内存泄漏
- [ ] **作业内容**：
    1. **概念**：
        - **普通指针**：就像“老式遥控器”，用完必须手动抠电池（`delete`），否则会漏电（内存泄漏）。
        - **智能指针**：就像“现代声控灯”，没人用时自动关掉！JS 里的变量其实都是智能指针，会自动回收。C++ 里我们要用 `std::shared_ptr`。
        - **对象切割 (Object Slicing)**：如果把 `GraduateStudent`（大盒子）硬塞进 `vector<Student>`（小盒子），多出来的“研究方向”会被切掉！必须用**指针**来存。
    2. **目标**：改造 `StudentManager`，用 `std::vector<std::shared_ptr<Student>>` 来存学生。
    3. **任务**：
        - **引入头文件**：`#include <memory>`。
        - **修改容器**：把 `std::vector<Student> students;` 改成 `std::vector<std::shared_ptr<Student>> students;`。
        - **修改添加逻辑**：`students.push_back(...)` 改成 `students.push_back(std::make_shared<Student>(...));`。
        - **测试**：试着把一个 `GraduateStudent` 放到这个列表里，看看打印出来是不是还能显示“研究方向”？
- [x] **状态**：已完成

## 16. 多态文件读写 (Polymorphic File I/O)
- [ ] **作业内容**：
    1. **问题**：现在的 `saveToFile` 只会保存普通学生的属性（因为调用的是 `getGrade` 等）。研究生的 `researchTopic` 存不进去，下次加载时就丢了。
    2. **目标**：让 `saveToFile` 能根据学生类型，自动保存不同的格式。
    3. **任务**：
        - **第一步 (虚函数)**：在 `Student.h` 里增加一个虚函数 `virtual std::string serialize() const;`，返回类似 `"1,张三,20,80,男"` 的字符串。
        - **第二步 (重写)**：在 `GraduateStudent.h` 里重写它，返回 `"1,张三,20,80,男,AI研究"`（多一项）。
        - **第三步 (修改保存)**：修改 `StudentManager::saveToFile`，不再手写拼接字符串，而是直接调用 `student->serialize()`。
        - **第四步 (修改加载)**：(选做/挑战) 修改 `loadFromFile`，读取时判断这一行如果有 6 项数据，就创建研究生，否则创建普通学生。
- [x] **状态**：已完成

## 17. Lambda 表达式与 STL 算法
- [ ] **作业内容**：
    1. **概念**：JS 里我们经常用 `array.find(item => item.id === 1)`。C++ 里也有 `std::find_if`！
    2. **目标**：消灭手写的 `for` 循环查找。
    3. **任务**：
        - 修改 `StudentManager::findStudentIndex`。
        - 引入 `<algorithm>`。
        - 使用 `std::find_if` 配合 Lambda 表达式来查找学生。
- [x] **状态**：已完成

## 18. 移动语义 (Move Semantics)
- [ ] **作业内容**：
    1. **概念**：体验“搬家”和“过户”的区别。
    2. **任务**：
        - **第一步 (拷贝构造)**：在 `Student.h` 和 `cpp` 里手动写一个拷贝构造函数 `Student(const Student& other)`。让它打印一句 `"Copying [name]..."`，然后老老实实把属性都抄一遍。
        - **第二步 (移动构造)**：在 `Student.h` 和 `cpp` 里写一个移动构造函数 `Student(Student&& other) noexcept`。
            - 让它打印一句 `"Moving [name]..."`。
            - 关键点：对于 `string` 类型的属性（name, gender），使用 `name = std::move(other.name)` 来“抢”资源。
            - 对于 `int/double` 属性，直接赋值。
        - **第三步 (测试)**：在 `main.cpp` 的 `main` 函数最前面：
            - 创建 `s1`。
            - `Student s2 = s1;` (观察是不是打印了 Copying)
            - `Student s3 = std::move(s1);` (观察是不是打印了 Moving)
            - 打印一下 `s1.getName()`，看看它还在不在？
- [x] **状态**：已完成

## 19. 多线程 (Multithreading)
- [ ] **作业内容**：
    1. **场景**：JS 里有 `setInterval` 可以定时做事。C++ 里我们可以开一个“后台线程”来实现自动备份，而且不会卡住主界面！
    2. **任务**：
        - **第一步 (定义任务)**：在 `main.cpp` 里写一个函数 `void autoSave(const StudentManager* manager)`。
            - 搞个死循环 `while(true)`。
            - 休息 5 秒：`std::this_thread::sleep_for(std::chrono::seconds(5));`。
            - 保存数据：`manager->saveToFile("backup.txt");`。
            - 打印一句 `[AutoBackup] Data saved.`。
        - **第二步 (启动线程)**：在 `main` 函数最开始（创建 manager 之后），启动线程。
            - `std::thread t(autoSave, &manager);`
            - `t.detach();` (关键！让它分离出去，在后台自生自灭，不要卡住主线程)。
        - **第三步 (头文件)**：别忘了 `#include <thread>` 和 `#include <chrono>`。
- [x] **状态**：已完成
