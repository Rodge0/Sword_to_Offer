// 11. 旋转数组的最小数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int findmin(vector<int>& numbers, int l, int r) {
    int minn = numbers[l];
    for (int i = l; i <= r; i++) {
        if (numbers[i] < minn) minn = numbers[i];
    }
    return minn;
}

// 二分查找
int minArray(vector<int>& numbers) {
    if (numbers.empty()) return 0;

    int l = 0;
    int r = numbers.size() - 1;
    int m = l;
    while (numbers[l] >= numbers[r]) {
        if (r - l == 1) {
            m = r;
            break;
        }
        m = (l + r) / 2;

        if (numbers[m] == numbers[l] && numbers[l] == numbers[r]) {
            return findmin(numbers, l, r);
        }
        if (numbers[m] >= numbers[l]) l = m;
        else r = m;
    }
    return numbers[m];
}

int main()
{
    vector<int> test = { 2,2,2,0,1 };
    std::cout << minArray(test) << std::endl;
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
