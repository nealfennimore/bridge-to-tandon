#include <iostream>

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {

    int arr[] = {5, 2, 11, 7, 6, 4};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    oddsKeepEvensFlip(arr, arrSize);

    for (int i = 0; i < arrSize; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}


void oddsKeepEvensFlip(int arr[], int arrSize) {
    int clone[arrSize];
    int oddCount = 0;
    int evenCount = arrSize - 1;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            clone[oddCount++] = arr[i];
        } else {
            clone[evenCount--] = arr[i];
        }
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = clone[i];
    }
}