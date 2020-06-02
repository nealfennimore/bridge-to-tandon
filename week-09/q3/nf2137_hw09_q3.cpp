#include <iostream>


// returns the base address of the array (containing the positive numbers),
// and updates the output parameter outPosArrSize with the array’s logical size.
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

// updates the output parameter outPosArr with the base address of the array
// (containing the positive numbers), and the output parameter outPosArrSize with
// the array’s logical size.
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);

// returns the base address of the array (containing the positive numbers), and uses
// the pointer outPosArrSizePtr to update the array’s logical size.
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);

// uses the pointer outPosArrPtr to update the base address of the array (containing
// the positive numbers), and the pointer outPosArrSizePtr to update the array’s
// logical size
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
    int arr1[6] = {3, -1, -3, 0, 6, 4};
    int arr1Size = sizeof(arr1)/sizeof(arr1[0]);
    int outPosArrSize1 = 0;
    int* positive1 = getPosNums1(arr1, arr1Size, outPosArrSize1);

    std::cout << "getPosNums1 positive output size: " << outPosArrSize1 << std::endl;
    std::cout << "getPosNums1 arr1 memory address: " << arr1 << std::endl;
    std::cout << "getPosNums1 positive memory address: " << positive1 << std::endl;

    std::cout << "***************************************" << std::endl;

    int arr2[6] = {3, -1, -3, 0, 6, 4};
    int arr2Size = sizeof(arr2)/sizeof(arr2[0]);
    int outPosArr2[arr2Size];
    int *outPosArr2Ptr = outPosArr2;
    int outPosArrSize2 = 0;
    getPosNums2(arr1, arr1Size, outPosArr2Ptr, outPosArrSize2);

    std::cout << "getPosNums2 positive output size: " << outPosArrSize2 << std::endl;
    std::cout << "getPosNums2 arr2 memory address: " << arr2 << std::endl;
    std::cout << "getPosNums2 positive memory address: " << outPosArr2 << std::endl;

    std::cout << "***************************************" << std::endl;

    int arr3[6] = {3, -1, -3, 0, 6, 4};
    int arr3Size = sizeof(arr3)/sizeof(arr3[0]);
    int outPosArrSize3 = 0;
    int *outPosArrSize3Ptr = &outPosArrSize3;
    int* positive3 = getPosNums3(arr3, arr3Size, outPosArrSize3Ptr);

    std::cout << "getPosNums3 positive output size: " << outPosArrSize3 << std::endl;
    std::cout << "getPosNums3 arr3 memory address: " << arr3 << std::endl;
    std::cout << "getPosNums3 positive memory address: " << positive3 << std::endl;

    std::cout << "***************************************" << std::endl;

    int arr4[6] = {3, -1, -3, 0, 6, 4};
    int arr4Size = sizeof(arr4)/sizeof(arr4[0]);
    int outPosArr4[arr4Size];
    int *outPosArr4Ptr = outPosArr4;
    int **outPosArr4Ptr2 = &outPosArr4Ptr;
    int outPosArrSize4 = 0;
    int *outPosArrSize4Ptr = &outPosArrSize4;
    getPosNums4(arr4, arr4Size, outPosArr4Ptr2, outPosArrSize4Ptr);

    std::cout << "getPosNums4 positive output size: " << outPosArrSize4 << std::endl;
    std::cout << "getPosNums4 arr4 memory address: " << arr4 << std::endl;
    std::cout << "getPosNums4 positive memory address: " << outPosArr4 << std::endl;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int clone[arrSize];
    int cloneIndex = 0;
    for (int i = 0; i < arrSize; ++i) {
        if ( arr[i] >= 0 ){
            clone[cloneIndex++] = arr[i];
        }
    }
    outPosArrSize = cloneIndex;
    return clone;
}
void getPosNums2(int* arr, int arrSize, int* &outPosArr, int& outPosArrSize){
    int cloneIndex = 0;
    for (int i = 0; i < arrSize; ++i) {
        if ( arr[i] >= 0 ){
            outPosArr[cloneIndex++] = arr[i];
        }
    }
    outPosArrSize = cloneIndex;
}
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr){
    int clone[arrSize];
    int cloneIndex = 0;
    for (int i = 0; i < arrSize; ++i) {
        if ( arr[i] >= 0 ){
            clone[cloneIndex++] = arr[i];
        }
    }
    *outPosArrSizePtr = cloneIndex;
    return clone;

}
void getPosNums4(int* arr, int arrSize, int **outPosArrPtr, int* outPosArrSizePtr){
    int *outPosArr = *outPosArrPtr; // Dereference pointer and initialize as a pointer to an array of ints
    int cloneIndex = 0;
    for (int i = 0; i < arrSize; ++i) {
        if ( arr[i] >= 0 ){
            outPosArr[cloneIndex++] = arr[i];
        }
    }
    *outPosArrSizePtr = cloneIndex;
}