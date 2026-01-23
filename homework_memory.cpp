#include <iostream>
#include <string>

// 一个简单的类，用来演示对象的创建和销毁
class House {
public:
    House(int id) : id(id) {
        std::cout << "🏠 House " << id << " 建好了 (构造函数)" << std::endl;
    }
    ~House (){
        std::cout << "退房";
    }
    void openDoor() {
        std::cout << "🔑 House " << id << " 的门打开了" << std::endl;
    }
private:
    int id;
};

int main() {
    std::cout << "=== 1. 栈上的房子 (自动管理) ===" << std::endl;
    {
        House h1(1); // 就像住酒店，离开大括号(退房)时自动拆掉
        h1.openDoor();
    } // <--- 这里会自动调用析构函数
    std::cout << "--------------------------------\n" << std::endl;


    std::cout << "=== 2. 堆上的房子 (new 手动管理) ===" << std::endl;
    // 任务 1: 使用 new 关键字创建一个 House 对象 (id 设为 2)
    // 提示: House* h2 = ...
    // 请在下面写代码:
    House* h2 = new House(1);
    
    // 任务 2: 调用它的 openDoor 方法
    // 提示: 指针要用箭头 ->
    // 请在下面写代码:
    {
        h2->openDoor();
    }

    std::cout << "   (现在程序快结束了，但 House 2 还在！)" << std::endl;
    
    // 任务 3: 把房子拆了 (防止内存泄漏)
    // 提示: delete ...
    // 请在下面写代码:
    delete h2;

    std::cout << "--------------------------------\n" << std::endl;

    std::cout << "=== 3. 数组的房子 (new[] 批量建造) ===" << std::endl;
    // 任务 4: 一次性建 3 个整数 (int)
    // 提示: int* numbers = new int[3];
    // 请在下面写代码:
    int* numbers = nullptr; // 请修改这一行
    numbers = new int[3];

    if (numbers != nullptr) {
        numbers[0] = 100;
        numbers[1] = 200;
        numbers[2] = 300;
        std::cout << "数组第二个元素是: " << numbers[1] << std::endl;

        // 任务 5: 拆除数组 (注意要用 delete[])
        // 提示: delete[] numbers;
        // 请在下面写代码:
        delete[] numbers;
        
    }

    return 0;
}
