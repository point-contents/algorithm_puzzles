#include <chrono>
#include <iostream>
#include <vector>

void pascalsTriangle(int n)
{
    long long arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                arr[i][j] = 1;
            } else
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int l = 0; l < k; l++) {
            std::cout << arr[k][l] << ",";
        }
        std::cout << "\n"
                  << std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Enter Exponent:" << std::endl;
    std::cin >> n;

    std::cout << "Pascals Triangle for " << n << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    pascalsTriangle(n);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << "\n\n\n Function Duration: " << duration << " microseconds"
              << std::endl;

    return 0;
}
