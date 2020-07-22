// 12. 矩阵中的路径.cpp : 此文件包含 'main' 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
    if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k]) return false;
    if (k == word.length() - 1) return true;
    char temp = board[i][j];
    board[i][j] = '/';
    bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1)
        || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
    board[i][j] = temp;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> test = { {'a','b','c','e'}, {'s','f','c','s'},{'a','d','e','e'} };
    vector<vector<char>> test1 = { {'A','B','C','E'}, {'S','F','C','S'},{'A','D','E','E'} };
    vector<vector<char>> test2 = { {'a', 'b'}, {'c', 'd'} };
    vector<vector<char>> test3 = { {'a','a'} };
    string word = "bfce";
    string word1 = "ABCCED";
    string word2 = "abcd";
    string word3 = "aa";

    cout << exist(test, word) << endl;
    cout << exist(test1, word1) << endl;
    cout << exist(test2, word2) << endl;
    cout << exist(test3, word3) << endl;

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
