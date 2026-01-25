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

## 20. 手动内存管理 (new/delete)
- [ ] **作业内容**：
    1. **概念**：
        - **栈 (Stack)**：就像**住酒店**。进房间（函数/作用域）时自动入住，出门时自动退房。干净省心，但房间大小有限。
        - **堆 (Heap)**：就像**买房子**。用 `new` 买房，这房子就永远是您的了。但是！如果您不卖掉它 (`delete`)，就算您人走了，房子也占着地（内存泄漏）。
    2. **任务**：
        - 打开 `homework_memory.cpp`。
        - 按照注释提示，用 `new` 创建对象，用 `delete` 销毁对象。
        - 体会一下如果没有 GC (垃圾回收)，程序员有多辛苦！
- [ ] **运行方法**：在终端输入 `make memory`
- [x] **状态**：已完成

## 21. 手写链表 (Linked List)
- [ ] **作业内容**：
    1. **概念**：链表就像**寻宝游戏**。你只有第一条线索 (Head)，每条线索 (Node) 里写着宝藏数据 (Data) 和下一条线索藏在哪 (Next Pointer)。
    2. **任务**：
        - 打开 `homework_linkedlist.cpp`。
        - 手动 `new` 三个节点。
        - 手动把它们连起来 (`next` 指针)。
        - 写个 `while` 循环遍历打印。
        - 最后别忘了 `delete`！
- [ ] **运行方法**：在终端输入 `make linkedlist`
- [x] **状态**：已完成

## 22. OpenGL 图形编程 (C++ 版 WebGL)
- [ ] **作业内容**：
    1. **概念**：WebGL 其实就是 OpenGL ES (嵌入式版本) 在浏览器里的封装。
    2. **任务**：
        - 进入目录 `cd opengl_learning`
        - 阅读 `main.cpp`，看看 `glfw` 和 `glew` 是怎么模拟 `<canvas>` 的。
        - 尝试编译运行 (注意：WSL 如果没有配置显示服务，可能会报错)。
- [ ] **运行方法**：`cd opengl_learning && make run` (如果报错，尝试 `make run-soft`)
- [x] **状态**：已完成

## 🎓 毕业总结 & 职业路线图

### 1. 你已经学会的 (The Basics)
| C++ 概念 | JS 类比 | 掌握程度 |
| :--- | :--- | :--- |
| **Class/Object** | ES6 Class | ✅ 已入门 |
| **Vector/Map** | Array / Object | ✅ 已入门 |
| **Pointers/Ref** | (无直接对应，类似引用传递) | ✅ 已入门 (难点!) |
| **Memory (new/delete)** | (无，JS全是自动GC) | ✅ 初步体验 |
| **Inheritance/Virtual** | Prototype Chain | ✅ 已入门 |
| **File I/O** | fs module | ✅ 已入门 |

### 2. 找工作必修课 (The Missing Pieces)
如果你想从事 C++ 开发，以下是必须攻克的难关：

#### A. 工程化构建 (CMake)
- **现状**：我们只用了简单的 `Makefile`。
- **目标**：学习 **CMake**。它是 C++ 界的 Webpack，管理大型项目必用。

#### B. 并发编程 (Concurrency)
- **现状**：接触了简单的 `std::thread`。
- **目标**：深入理解 **锁 (Mutex)**、**原子操作 (Atomic)**、**线程池 (Thread Pool)**。这是后端/游戏开发的核心。

#### C. 网络编程 (Networking)
- **现状**：还是单机版程序。
- **目标**：学习 **Socket 编程** (TCP/UDP)，让程序能联网交互 (类似写 Node.js 后端)。

#### D. 数据结构与算法 (Algorithm)
- **目标**：刷 LeetCode。链表只是开始，二叉树、哈希表、排序算法是面试必问。

#### E. 操作系统基础 (Linux OS)
- **目标**：熟悉 Linux 命令，理解进程/线程区别，内存管理机制。

### 3. 推荐方向
1.  **Qt 桌面开发**：继续完善你的 Qt 学习，适合做客户端工具 (类似 Electron)。
2.  **后台/服务器开发**：高性能服务器 (类似 Go/Java 但更快)，需要精通 Linux 和网络。
3.  **嵌入式/音视频**：需要更底层的硬件知识。

**祝贺你完成了 C++ 速成班的所有作业！🚀**

恭喜奶奶！您已经完成了从 C++ 入门到进阶的全部课程！🎉
这里有一份**C++ 知识点对照表**，帮您复习这些“老管家”的规矩：

| 概念 | C++ (严谨的老管家) 🧐 | JS (灵活的小伙子) 😎 | 奶奶掌握情况 |
| :--- | :--- | :--- | :--- |
| **打印** | `std::cout << "..."` | `console.log("...")` | ✅ 滚瓜烂熟 |
| **变量声明** | `int`, `double`, `string` (必须说清楚) | `var`, `let`, `const` (随便装) | ✅ 已掌握 |
| **数组** | `std::vector` (动态数组) | `Array` | ✅ 已掌握 |
| **循环** | `for (auto x : list)` | `for (let x of list)` | ✅ 已掌握 |
| **引用/指针** | `&` (别名), `*` (遥控器) | (JS 全是引用，没得选) | ✅ 已掌握 |
| **类与对象** | `class` + `public/private` | `class` (ES6) | ✅ 已掌握 |
| **继承** | `: public Student` | `extends Student` | ✅ 已掌握 |
| **多态** | `virtual` (虚函数) | 默认支持 | ✅ 已掌握 |
| **字典/Map** | `std::map` | `Object` / `Map` | ✅ 已掌握 |
| **泛型** | `template <typename T>` | (TS 泛型 / 动态类型) | ✅ 已掌握 |
| **异常处理** | `try...catch` | `try...catch` | ✅ 已掌握 |
| **智能指针** | `std::shared_ptr` (自动关灯) | (自动垃圾回收) | ✅ 已掌握 |
| **多线程** | `std::thread` | `Web Workers` | ✅ 初步体验 |

**下一步建议**：
1. **休息一下**：您已经学得很快了，喝杯茶！🍵
2. **实战项目**：如果有兴趣，可以尝试用 C++ 写个小游戏或者工具。
