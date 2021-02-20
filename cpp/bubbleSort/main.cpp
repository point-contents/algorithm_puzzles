#include <assert.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << "\n";

template <typename T>
void printVec(T vec) {
    for (auto& things : vec) {
	std::cout << things << ",";
    }
    std::cout << "\n";
}

std::vector<int> bubbleSort(std::vector<int> vec) {
    std::vector<int> outputVec;
    bool swapped = false;
    for (int j = 0; j < vec.size(); j++) {
	swapped = false;
	for (int i = 0; i < vec.size(); i++) {
	    if (vec[i] < vec[i + 1]) {
		continue;
	    } else if (vec[i] == vec[i + 1]) {
		continue;
	    } else if (vec[i] > vec[i+1]){
		int placeholder;
		placeholder = vec[i + 1];
		vec[i + 1] = vec[i];
		vec[i] = placeholder;

		swapped = true;
	    }
	}
	if (swapped == false) {
	    break;
	}
    }
    return vec;
}

std::vector<int> createVec(int n, int t = 15) {
    std::vector<int> output;
    output.reserve(n);
    for (int i = 0; i < n; i++) {
	int randomN = std::rand() % t;
	output.push_back(randomN);
    }
    return output;
}

int main() {
    std::vector<int> a = {0,3,5,3,2,3,6,6}; 
    LOG("Pre Sorted");
    printVec(a);

    std::vector<int> b = bubbleSort(a);

    LOG("Post Sort");
    printVec(b);

    return 0;
}
