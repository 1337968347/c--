#include <iostream>
#include <string>

// 一个简单的学生结构体 (Struct)
// Struct 和 Class 很像，只不过默认大家都是 public 的，方便我们练习数据操作
struct MiniStudent {
    std::string name;
    int grade;
};

int main() {
    std::cout << "\n=== C++ 指针入门练习 (Pointer Playground) ===\n" << std::endl;

    // --- 第一部分：基础类型的指针 ---
    int number = 100;
    
    std::cout << "1. 现在的 number 是: " << number << std::endl;

    // 任务 1: 定义一个指针 p，让它指向 number
    // 提示: int* p = &number;   (& 意思是取地址，就像获取门牌号)
    // 请在下面写代码:
    int *p = &number;

    
    // (取消下面这行的注释来验证)
    std::cout << "   指针 p 存储的地址是: " << p << " (这就是 number 的门牌号)" << std::endl;


    // 任务 2: 通过指针 p 修改 number 的值为 200
    // 提示: *p = 200;    (* 意思是“顺藤摸瓜”，找到地址里住的人)
    // 请在下面写代码:
    *p = 200;

    std::cout << "2. 修改后 number 应该是 200: " << number << std::endl;
    if (number == 200) std::cout << "   (恭喜！修改成功！)" << std::endl;
    else std::cout << "   (还没改对哦，加油)" << std::endl;


    // --- 第二部分：对象指针 (模拟“选中”学生) ---
    std::cout << "\n--- 进阶：用指针选中学生 ---" << std::endl;
    
    MiniStudent s1 = {"小明", 80};
    MiniStudent s2 = {"小红", 90};

    // 创建一个指针，一开始谁都没选中 (nullptr 就是空，类似 JS 的 null)
    MiniStudent* currentSelected = nullptr; 

    // 任务 3: 让 currentSelected 指向 s2 (假装我们在列表里点击了“小红”)
    // 提示: currentSelected = &s2;
    // 请在下面写代码:
    currentSelected = &s2;

    // 任务 4: 通过 currentSelected 把 s2 的成绩改成 99
    // 提示: 
    // 方法A (笨办法): (*currentSelected).grade = 99;
    // 方法B (常用法): currentSelected->grade = 99;   (-> 是个箭头，意思是“指向它的...”)
    // 请在下面写代码:
    (*currentSelected).grade = 99;

    std::cout << "3. 小红现在的成绩应该是 99: " << s2.grade << std::endl;
    if (s2.grade == 99) std::cout << "   (太棒了！您已经掌握了 C++ 指针的核心用法！)" << std::endl;
    else std::cout << "   (还没变哦，再检查一下箭头 -> 用法)" << std::endl;

    std::cout << "\n=============================================\n" << std::endl;
    return 0;
}
