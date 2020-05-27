#include <iostream>
#include <vector>
#include <climits>

int minInArray(int arr[], int arrSize);

int main() {
    std::cout << "Please enter 20 integers seperated by a space:" << std::endl;
    int arr[20];
    for (int i = 0; i < 20; ++i) {
        int n;
        std::cin >> n;
        arr[i] = n;
    }

    int min = minInArray(arr, 20);

    std::cout << "The minimum value is " << min << ", and it is located in the following indices:";
    for (int j = 0; j < 20; ++j) {
        if (arr[j] == min){
            std::cout << " " << j;
        }
    }

    return 0;
}

int minInArray(int arr[], int arrSize) {
    int n = INT_MAX;
    for (int i = 0; i < arrSize; ++i) {
        int item = arr[i];
        if (item < n) {
            n = item;
        }
    }
    return n;
}