// 04. 二维数组中的查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 暴力
bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
    // 无需添加判断空
    if (matrix.empty()) return false;
    for (auto i : matrix) {
        for (auto j : i) {
            if (j == target) return true;
        }
    }
    return false;
}

// 从右上角向左下角开始查找
bool findNumberIn2DArray2(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    // 无需判断第一行元素为空，为空j=-1
    for (int i = 0, j = matrix[0].size() - 1; i <matrix.size() && j >= 0; ) {
        if (matrix[i][j] > target) j--;
        else if (matrix[i][j] < target) i++;
        else return true;
    }
    return false;
}

// 从左上角向右上角开始查找
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    if (matrix[0].empty()) return false;
    for (int i = matrix.size() - 1, j = 0; i>=0 && j <= matrix[0].size()-1; ) {
        if (matrix[i][j] > target) i--;
        else if (matrix[i][j] < target) j++;
        else return true;
    }
    return false;
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
