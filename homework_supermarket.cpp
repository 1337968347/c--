#include <iostream>
#include <map> // 👈 必须引入 map 头文件
#include <string>
#include <vector>

// 👵 题目：超市收银台
// 目标：练习类 (Class)、字典 (Map) 和 简单的逻辑
// 前端回忆：这就像写一个简单的 Shopping Cart 逻辑。

// 任务 1: 定义一个“收银机”类
// 名字叫 CashRegister
// ------------------------------------------------
class CashRegister {
private:
  // 任务 2: 定义一个私有变量，存商品价格
  // 类型是 std::map<std::string, double>
  // 名字叫 prices
  // 这就像 JS 里的 const prices = { "苹果": 5.5, "香蕉": 3.0 };
  // [请在下面写代码] (1 行)
  std::map<std::string, double> prices;

public:
  // 任务 3: 实现“上货”方法 (添加商品价格)
  // 函数名: addProduct
  // 参数: name (string), price (double)
  // 逻辑: 把名字和价格存进 prices 里
  // 提示: prices[name] = price;
  // [请在下面写代码] (3-4 行)
  void addProduct(std::string name, double price) { prices[name] = price; }

  // 任务 4: 实现“结账”方法
  // 函数名: checkout
  // 参数: cart (std::vector<std::string> 类型，表示购物车里的商品名字列表)
  // 返回值: double (总金额)
  // 逻辑:
  //    1. 定义一个 total = 0.0;
  //    2. 遍历购物车里的每个商品名 (for item : cart)
  //    3. 查表 prices 看看这个商品多少钱
  //       (注意：可以用 prices.count(item) 检查有没有这个商品，防止报错，
  //        或者简单点直接 total += prices[item]，如果不存在默认是 0)
  //    4. 返回 total
  // [请在下面写代码] (大约 6-8 行)
  double checkout(const std::vector<std::string> &cart) {
    double total = 0.0;
    // 请补全循环逻辑...
    for (const auto &item : cart) {
      if (prices[item] > 0) {
        total += prices[item];
      }
    }

    return total;
  }
};

int main() {
  std::cout << "=== 🛒 欢迎光临 C++ 超市 ===" << std::endl;

  // 1. 创建收银机
  CashRegister reg;

  // 2. 录入商品价格
  std::cout << "--- 正在录入商品价格 ---" << std::endl;
  reg.addProduct("苹果", 5.5);
  reg.addProduct("香蕉", 3.2);
  reg.addProduct("牛奶", 12.0);
  // 您可以再加几个喜欢的商品...

  // 3. 模拟顾客的购物车
  std::vector<std::string> myCart;
  myCart.push_back("苹果");
  myCart.push_back("苹果"); // 买两个苹果
  myCart.push_back("牛奶");
  myCart.push_back("香蕉");
  myCart.push_back(
      "茅台"); // 这个商品我们没录入价格，看看会发生什么？(Map 默认会给 0)

  // 4. 结账
  std::cout << "--- 正在结账 ---" << std::endl;
  double total = reg.checkout(myCart);

  std::cout << "您的购物车总金额是: " << total << " 元" << std::endl;

  // 任务 5 (挑战): 简单的测试
  // 手算一下：5.5 + 5.5 + 12.0 + 3.2 = 26.2
  // 看看程序算得对不对？

  return 0;
}
