#include <assert.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << "\n";

template <typename T>
void printVec(T vec) {
    for (auto& things : vec) {
	std::cout << things << "\n";
    }
}

int maxSequence(const std::vector<int>& arr) {
    int maxInitial = 0;
    int maxEnding = 0;

    for (auto num : arr) {
		maxEnding = maxEnding + num;
		if (maxInitial < maxEnding) { maxInitial = maxEnding; }
		if (maxEnding < 0) { maxEnding = 0; }
    }
    return maxInitial;
}

int main() {
    std::vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSequence(a);

    return 0;
}
