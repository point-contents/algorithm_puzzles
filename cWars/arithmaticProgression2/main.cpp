#include <iostream>
#include <vector>

static long findMissing(std::vector<long> list) {
    long answer;
    long previousDifference = 0;
    long currentValue;

    for (size_t i = 0; i < list.size() - 1; i++) {
	long currentDifference = list[i + 1] - list[i];
	currentValue = list[i];
	if (previousDifference != 0 &&
	    currentDifference != previousDifference) {
	    answer = list[i] + previousDifference;
	} else {
	    if (list[i + 1] > list.size()) {
		continue;
	    } else {
		previousDifference = list[i + 1] - list[i];
	    }
	}
    }
    return answer;
}

int main() {
    //    std::cout << findMissing({1, 2, 3, 5}) << std::endl;
    //    std::cout << findMissing({1, 2, 3, 5, 6, 7, 8, 9, 10, 11}) <<
    //    std::endl;
    std::cout << findMissing({1, 5, 7}) << std::endl;

    return 0;
}
