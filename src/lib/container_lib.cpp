//
// Created by shyoung.kim on 2021-02-18.
//
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<class T>
class Heap {
private:
    void swap(int i, int j) {
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }

    void heapifyTopDown() {
        for (int endIndex = 1; endIndex < list.size(); endIndex++) {
            siftUp(endIndex);
        }
    }

    void heapifyBottomUp() {
        for (int heapIndex = (list.size() - 2) / 2; heapIndex > -1; heapIndex--) {
            siftDown(heapIndex);
        }
    };

    void siftUp(int index) {
        while (index > -1) {
            int parentIndex = (index - 1) / 2;
            if (compare(list[index], list[parentIndex])) {
                swap(index, parentIndex);
                index = parentIndex;
            } else {
                return;
            }
        }
    }

    void siftDown(int heapIndex) {
        int leftIndex = (heapIndex * 2) + 1;
        int rightIndex = leftIndex + 1;

        while (leftIndex < list.size()) {
            int newIndex = heapIndex;

            if (compare(list[leftIndex], list[newIndex])) {
                newIndex = leftIndex;
            }

            if (rightIndex < list.size() && compare(list[rightIndex], list[newIndex])) {
                newIndex = rightIndex;
            }

            if (newIndex != heapIndex) {
                swap(newIndex, heapIndex);
                heapIndex = newIndex;
                leftIndex = (heapIndex * 2) + 1;
                rightIndex = leftIndex + 1;
            }
            else {
                return;
            }
        }
    }
public:
    vector<T> list;
    function<bool(T&,T&)> compare;

    Heap() {
        list.clear();
        compare = [](T& left, T& right)->bool{
            return left < right;
        };
    }

    Heap(function<bool(T&, T&)> comp) {
        list.clear();
        compare = comp;
    }

    void push(T obj) {
        list.push_back(obj);
        siftUp(list.size() - 1);
        print();
    }

    T top() {
        if (list.size() == 0) {
            return NULL;
        }

        return list[0];
    }

    T pop() {
        T result = list[0];

        swap(0, list.size() - 1);
        list.pop_back();
        siftDown(0);

        return result;
    }

    bool isEmpty() {
        return list.size() == 0;
    }

    void print() {
#ifdef DEBUG
        cout << "list : ";
        for_each(list.begin(), list.end(), [](T t)->void{
            cout << t << " ";
        });
        cout << endl;
#endif
    }
};


int main(int argc, char** argv) {
    int arr[9] = {485,241,454,325,452,685,498,890,281};

    Heap<int> heap;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        heap.push(arr[i]);
    }

    while (!heap.isEmpty()) {
        cout << heap.pop() << endl;
        heap.print();
    }

}

