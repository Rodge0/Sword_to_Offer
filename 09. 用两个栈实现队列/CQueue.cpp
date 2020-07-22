#include "CQueue.h"

CQueue::CQueue() {
	while (!first.empty()) {
		first.pop();
	}
	while (!second.empty()) {
		second.pop();
	}
}

void CQueue::appendTail(int value) {
	first.push(value);
}

int CQueue::deleteHead() {
	/*if (second.empty()) {
		while (!first.empty()) {
			second.push(first.top());
			first.pop();
		}
		if (second.empty()) return -1;
		else {
			int temp = second.top();
			second.pop();
			return temp;
		}
	}*/

	// ∂‡Àºøº£¨
	if (second.empty() && first.empty()) {
		return -1;
	}
	if (second.empty() && !first.empty()) {
		while (!first.empty()) {
			second.push(first.top());
			first.pop();
		}
	}
	int res = second.top();
	second.pop();
	return res;
}



