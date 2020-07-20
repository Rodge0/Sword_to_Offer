// 10- I. 斐波那契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

#include <iostream>
#include <vector>

using namespace std;

int fib1(int n) {
    if (n < 0) return 0;
    long modd = 1e9 + 7;
    vector<int> fibo(n + 1);

    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= n; i++) {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % modd;
    }

    return fibo[n];
}

// 优化空间
int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    int f1 = 0, f2 = 1;
    for (int i = 1; i < n; i++) {
        int temp = f2;
        f2 = (f1 + f2) % 1000000007;
        f1 = temp;
    }
    return f2;
}

int main()
{
    int n;
    while (cin >> n) {
        cout << fib(n) << endl;
    }
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
