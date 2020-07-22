// 06. 从尾到头打印链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> reversePrint1(ListNode* head) {
    vector<int> res;
    if (!head) return res;
    while (head) {
        res.emplace_back(head->val);
        head = head->next;
    }
    for (int i = 0; i < res.size() / 2; i++) {
        swap(res[i], res[res.size() - 1 - i]);
    }
    return res;
}

// 递归 
vector<int> reversePrint2(ListNode* head) {
    if (!head) return {};
    vector<int> res = reversePrint2(head->next);
    res.emplace_back(head->val);
    return res;
}

// 栈  更快
vector<int> reversePrint(ListNode* head) {
    if (!head) return {};
    stack<int> mystack;
    while (head) {
        mystack.push(head->val);
        head = head->next;
    }
    vector<int> res;
    while (!mystack.empty()) {
        res.emplace_back(mystack.top());
        mystack.pop();
    }
    return res;
}

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
