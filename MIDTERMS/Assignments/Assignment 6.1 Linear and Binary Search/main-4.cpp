#include <iostream>

// Linear Search
int LinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            std::cout << "Target found!";
            return i;
        }
        else 
            if (i == size - 1) {
                std::cout << "Target not found in the list.";
        }
    }
    return -1;
}

// Binary Search
int BinarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    int f = 0, i;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            std::cout << "Target found in the List!";
            return mid;
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }


    std::cout << "Target not found in the list.";
    return -1; 
}

// main
int main() {
    int list1[5] = {7, 9, 12, 15, 38};
    int size1 = 5;

    int list2[5] = {2, 5, 6, 12, 38};
    int size2 = 5;

    int number;

    std::cout << "Please Enter a Number to Search in the list: ";
    std::cin >> number;

    int linearResult = LinearSearch(list1, size1, number);
    if (linearResult != -1)
        std::cout << "\nLinear Search has determined its in: " << linearResult << std::endl;

    int binaryResult = BinarySearch(list2, size2, number);
    if (binaryResult != -1)
        std::cout << "\nBinary Search has determined its in: " << binaryResult << std::endl;

    return 0;
}