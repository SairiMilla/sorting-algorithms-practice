// SortingAlgorithmsPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>  
using namespace std;


void printArray(int* arr,int n) {
    cout << "[";
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << "]" << endl;
}
void quicksort(int* arr, int lo, int hi) {

    if (hi <= lo) {
        return;
    }
    int mid = lo + ((hi - lo) / 2);

    if (hi - lo + 1 >= 9) {
        if (arr[mid] < arr[0]) {
            swap(arr[mid], arr[0]);
        }
        if(arr[mid] > arr[hi]) {
            swap(arr[hi], arr[mid]);
        }
    }

    int gt = hi, lt = lo, i = lo;

    swap(arr[lo], arr[mid]);

    int pivot = arr[lo];

    while (i <= gt) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[lt]);
            ++lt;
            ++i;
        }
        else if (arr[i] > pivot) {
            swap(arr[i], arr[gt]);
            --gt;
        }
        else {
            ++i;
        }
    }
    quicksort(arr, lo, lt - 1);
    quicksort(arr, gt + 1, hi);
    
}

void merge(int* arr, int* aux, int lo, int mid, int hi) {
    int i = lo;
    int j = mid + 1;
    int k = lo;

    for (int h = lo; h <= hi; ++h) {
        aux[h] = arr[h];
    }

    while (k <= hi) {
        if (j > hi) {
            arr[k] = aux[i++];
        }
        else if(i > mid) {
            arr[k] = aux[j++];
        }
        else if (aux[j] < aux[i]) {
            arr[k] = aux[j++];
        }
        else {
            arr[k] = aux[i++];
        }
        k++;
    }
    
}

void mergeSortAux(int* arr, int* aux, int lo, int hi) {
    if (hi <= lo) {
        return;
    }

    int mid = lo + (hi - lo) / 2;

    mergeSortAux(arr, aux, lo, mid);
    mergeSortAux(arr, aux, mid + 1, hi);

    merge(arr, aux, lo, mid, hi);
}

void mergeSort(int* arr, int size) {
    int* aux = new int[size];

    mergeSortAux(arr, aux, 0, size - 1);
}

int main()
{
    int arr[] = { 7, 8, 9,34, 5,23,567,8,3 ,23,564 };

    printArray(arr, 11);

    quicksort(arr, 0, 10);

    printArray(arr, 11);

    int arr2[] = { 7, 8, 9,34, 5,23,567,8 };

    printArray(arr2, 8);

    mergeSort(arr2, 8);

    printArray(arr2, 8);
}

