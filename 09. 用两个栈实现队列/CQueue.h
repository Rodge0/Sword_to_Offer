#pragma once
#include <stack>

class CQueue
{
private:
    std::stack<int> first, second;
public:
    CQueue();
    void appendTail(int value);
    int deleteHead();
};

