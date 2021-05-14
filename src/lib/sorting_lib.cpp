#include "header/sorting_lib.h"

template<class T> void selectionSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp) {
    for (int i = left; i < right; i++) {
        int max_index = i;

        for (int j = i + 1; j <= right; j++) {
            if (comp(list[j], list[max_index])) {
                max_index = j;
            }
        }

        if (i != max_index) {
            //swap(list[i], list[max_index]);
            T temp = list[i];
            list[i] = list[max_index];
            list[max_index] = temp;
        }
    }
}

template<class T> void insertionSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp) {
    for (int i = left + 1; i <= right; i++) {
        for (int j = i; j > 0 && comp(list[j], list[j - 1]); j--) {
            //swap(list[j], list[j - 1]);
            T temp = list[j];
            list[j] = list[j - 1];
            list[j - 1] = temp;
        }

    }
}

template<class T> void bubbleSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp) {
    for (int i = left; i < right; i++) {
        bool isSwapped = false;

        for (int j = left; j < right - i + left; j++) {
            if (comp(list[j + 1], list[j])) {
                //swap(list[j], list[j + 1]);
                T temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                isSwapped = true;
            }
        }

        if (!isSwapped) {
            break;
        }
    }
}

template<class T> void quickSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp) {
    if (left >= right) {
        return;
    }

    int index = left;
    const int pivot = left;

    for (int i = left + 1; i <= right; i++) {
        if (comp(list[i], list[pivot])) {
            swap(list[i], list[++index]);
        }
    }

    swap(list[pivot], list[index]);
    quickSort(list, left, index - 1, comp);
    quickSort(list, index + 1, right, comp);
}

template<class T> void mergeSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(list, left, mid, comp);
    mergeSort(list, mid + 1, right, comp);


    // Merge left / right
    vector<T> sorted(right - left + 1);

    int l = left;
    int r = mid + 1;
    int index = 0;
    while (l <= mid && r <= right) {
        if (comp(list[l], list[r])) {
            sorted[index++] = list[l++];
        }
        else {
            sorted[index++] = list[r++];
        }
    }
    while (l <= mid) {
        sorted[index++] = list[l++];
    }
    while (r <= right) {
        sorted[index++] = list[r++];
    }

    for (int i = left, index = 0; i <= right; i++) {
        list[i] = sorted[index++];
    }
}

template<class T> void heapSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp) {
    Heap<T> heap(comp);
    for (int i = left; i <= right; i++) {
        heap.push(list[i]);
    }

    for (int i = left; i <= right; i++) {
        list[i] = heap.pop();
    }
}