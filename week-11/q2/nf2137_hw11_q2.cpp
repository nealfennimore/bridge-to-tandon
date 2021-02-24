#include <iostream>
#include <cmath>

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4};

    std::cout << "sumOfSquares" << std::endl;
    std::cout << sumOfSquares(arr, 4) << std::endl;

    std::cout << "isSorted" << std::endl;
    std::cout << isSorted(arr, 4) << std::endl;

    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    if ( arrSize <= 0 ) {
        return 0;
    }
    return sumOfSquares(arr, arrSize - 1) + pow(arr[arrSize - 1], 2);
}

bool isSorted(int arr[], int n) {
    if (n == 1 || n == 0) {
        return true;
    }

    if (arr[n - 1] < arr[n - 2]) {
        return false;
    }

    return isSorted(arr, n - 1);
}