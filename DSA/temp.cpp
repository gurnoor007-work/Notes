#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    std::vector<int> arr;

    // Generate 1000 unique numbers
    for (int i = 1; i <= 100000; i++)
        arr.push_back(i);

    // Shuffle them
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);

    // Print as a C++ array
    std::cout << "{";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i != arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}";
}