#include <iostream>

// 链表节点结构体
struct Node {
  int data;   // 数据
  Node *next; // 指向下一个节点的指针

  // 构造函数
  Node(int val) : data(val), next(nullptr) {}
};

int main() {
  std::cout << "=== 手写链表 (Linked List) ===" << std::endl;

  // 任务 1: 创建三个独立的节点 (必须使用 new 在堆上创建)
  // 数据分别是 10, 20, 30
  // 变量名建议叫 n1, n2, n3
  // ------------------------------------------
  Node *n1 = new Node((10));
  Node *n2 = new Node((20));
  Node *n3 = new Node((30));

  // 任务 2: 把它们连起来！ (n1 -> n2 -> n3)
  // 让 n1 的 next 指向 n2
  // 让 n2 的 next 指向 n3
  // ------------------------------------------
  n1->next = n2;
  n2->next = n3;
  n3->next = nullptr;

  // 任务 3: 遍历打印
  // 1. 定义一个 Node* 类型的 current 指针，让它指向表头 (n1)
  // 2. 使用 while 循环，条件是 current 不等于 nullptr
  // 3. 在循环里：
  //      a) 打印 current->data
  //      b) 让 current 移动到下一个节点 (指向 next)
  // ------------------------------------------
  std::cout << "链表内容: ";

  Node *current = n1;

  while (current != nullptr) {
    std::cout << current->data << std::endl;
    current = current->next;
  }
  std::cout << "NULL" << std::endl;

  // 任务 4: 释放内存 (防止内存泄漏)
  // 所有的 new 都要对应 delete。
  // 请把 n1, n2, n3 都 delete 掉。
  // (进阶挑战：如果你能用 while 循环配合一个 temp 指针来删除，那是最好的！)
  // ------------------------------------------
  current = n1;
  while (current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }

  return 0;
}
