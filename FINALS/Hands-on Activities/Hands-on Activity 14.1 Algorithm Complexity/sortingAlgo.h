#include <cstddef>
#include <iostream>
#ifndef SORTINGALGO_H
#define SORTINGALGO_H


// ------------------ Bubble Sort -------------------- 
template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] > arr[j])
                std::swap(arr[i], arr[j]);
        }
    }
}


// ------------------ Selection Sort -------------------- 
template<typename T>
int routineSmallest(T arr[], int K, const int arrSize) {
    int position;
    T smallestElem = arr[K];

    for(int j = K + 1; j < arrSize; j++) {
        if(arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;

}

template<typename T>
int selectionSort(T arr[], size_t arrSize) {
    int POS, temp, pass;
    for(int i = 0; i < arrSize; i++) {
        POS = routineSmallest(arr, i, arrSize);

        //swapping
        temp = arr[i];

        arr[i] = arr[POS];
        arr[POS] = temp;

        //for verification and counting no of passes that was done
        pass++;
    }

    
}

// ------------------ Insertion Sort -------------------- 
template<typename T>
void insertionSort(T arr[], size_t arrSize) {
    int K = 0, J, temp;

    while(K < arrSize) {
        temp = arr[K];
        J = K - 1;
        
        while(J >= 0 && arr[J] > temp) {
            arr[J+1] = arr[J];
            J--;
        }

        arr[J+1] = temp;
        K++;
    
    }
}


// ------------------ Shell Sort -------------------- 
template<typename T>
void shellSort(T arr[], size_t arrSize) {
    int K, J, temp;

    // outer loop: shrink the gap each pass (size/2, size/4, ..., 1)
    for (int gap = arrSize / 2; gap > 0; gap /= 2) {

        // from insertionSort
        K = gap;               
        while (K < arrSize) {
            temp = arr[K];
            J = K - gap;     

            // shift earlier gap-sorted elements up until the correct  location for arr[i] is found
            while (J >= 0 && arr[J] > temp) {
                arr[J + gap] = arr[J];   
                J -= gap;                 
            }

            arr[J + gap] = temp; 
            K++;
        }
    }
}

// ------------------ Merge Sort -------------------- 
template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  //size of left sub-array
    int n2 = right - mid;    // size of right sub-array

    // Temporary arrays to hold sub-array data
    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    int i = 0, j = 0, k = left;
 
    // merge the temp arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // copy any remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // copy any remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
 
    delete[] L;
    delete[] R;
}

// Recursive helper that operates on index range [left, right]
template <typename T>
void mergeSortHelper(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
 
        mergeSortHelper(arr, left, mid);       // sort first half
        mergeSortHelper(arr, mid + 1, right);  // sort second half
        merge(arr, left, mid, right);          // merge sorted halves
    }
}
 
// for calling the function
template <typename T>
void mergeSort(T arr[], size_t arrSize) {
    if (arrSize > 0)
        mergeSortHelper(arr, 0, arrSize - 1);
}



// ------------------ Quick Sort -------------------- 
// Partitions arr[low..high] using arr[high] as the pivot.
// Elements less than pivot end up on its left, greater on its right.
// Returns the final index of the pivot.

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1; // index of last element smaller than pivot
 
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
 
    std::swap(arr[i + 1], arr[high]); // place pivot at its correct position
    return i + 1;
}
 
// Recursive helper that operates on index range [low, high]
template <typename T>
void quickSortHelper(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
 
        quickSortHelper(arr, low, pivotIndex - 1);   // sort left sub list
        quickSortHelper(arr, pivotIndex + 1, high);  // sort right sub list
    }
}

template <typename T>
void quickSort(T arr[], size_t arrSize) {
    if (arrSize > 0)
        quickSortHelper(arr, 0, arrSize - 1);
}
 
 



#endif