#include <iostream>
#include <string>
#include <vector>

// 👵 题目：我的私房菜谱
// 目标：练习结构体 (struct)、动态数组 (vector) 和 循环
// 既然前面的都做完了，我们来个轻松有趣的！

// 任务 1: 定义一个“菜谱”结构体
// 名字叫 Recipe
// 里面有两个属性：
// 1. name (std::string 类型，表示菜名)
// 2. score (int 类型，表示难度打分 1-5)
// ------------------------------------------------
// [请在下面写代码] (大约 4-5 行)
struct Recipe {
  std::string name;
  int score;

  void printf() const {
    std::cout << "名字是: " << name << "分值是：" << score << std::endl;
  }
};
// ------------------------------------------------

int main() {
  std::cout << "=== 🍳 奶奶的私房菜谱 ===" << std::endl;

  // 任务 2: 创建一个列表，用来存菜谱
  // 类型是 std::vector<Recipe>
  // 变量名叫 myCookbook
  // ------------------------------------------------
  // [请在下面写代码] (1 行)
  std::vector<Recipe> myCookbook;
  // ------------------------------------------------

  // 任务 3: 往列表里加 3 道菜
  // 比如："红烧肉" (5分), "拍黄瓜" (1分), "番茄炒蛋" (2分)
  // 提示: myCookbook.push_back({ "菜名", 分数 });
  // ------------------------------------------------
  // [请在下面写代码] (3 行)
  myCookbook.push_back({"红烧肉", 5});
  myCookbook.push_back({"拍黄瓜", 1});
  myCookbook.push_back({"番茄炒蛋", 2});

  // 任务 4: 打印出所有菜谱
  // 使用 for (const auto& dish : myCookbook) 循环
  // 打印格式：[难度: 5] 红烧肉
  // ------------------------------------------------
  std::cout << "--- 正在翻看菜谱 ---" << std::endl;
  // [请在下面写代码] (大约 3-4 行)
  for (const Recipe &book : myCookbook) {
    book.printf();
  }
  // ------------------------------------------------

  // 任务 5 (挑战): 找出难度大于 3 的“大菜”
  // 遍历列表，如果 score > 3，就打印它的名字
  // ------------------------------------------------
  std::cout << "--- 今天的硬菜 (难度 > 3) ---" << std::endl;
  // [请在下面写代码] (大约 3-5 行)
  for (const Recipe &book : myCookbook) {
    if (book.score > 3) {
      std::cout << book.name << std::endl;
    }
  }
  // ------------------------------------------------

  return 0;
}
