## SW검정 문제풀이
- [x] [Intermediate](./src/Intermediate)
- [ ] [Advanced](./src/Advanced)
- [ ] [Professional](./src/Professional)
- [ ] [Expert](./src/Expert)

---
## Template Source
<details>
  <summary>Details</summary>
  <p>

```c++
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <limits>
//#include "lib/header/string_lib.h"

#define TEST
//#define STRING_TRIM

/*************************************************************************/
// Libarary Function
/*************************************************************************/
std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, char delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, std::string delimiter);

#ifdef STRING_TRIM
void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);
std::string ltrim_copy(std::string s);
std::string rtrim_copy(std::string s);
std::string trim_copy(std::string s);
#endif
/*************************************************************************/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_N 11
#define SPACE_STR " "
#define STAR_STR "*"
#define SPACE_CHAR ' '
#define STAR_CHAR '*'

int T;
int N;
int topHeight[MAX_N][MAX_N];

int main(int argc, char **argv)
{
    #ifdef TEST
    std::string filePath = "../src/sample_input.txt";
    
    // read File
    std::ifstream inputFileStream;
    inputFileStream.open(filePath, std::ios_base::in);
    if (inputFileStream.is_open())
    {
        std::cin.rdbuf(inputFileStream.rdbuf()); // swap
    }
    #endif
    
    std::string input;
    std::vector<std::string> input_list;
    
    input_list = getInputListFromInputstreamLine(std::cin, SPACE_CHAR);
    T = std::atoi(input_list[0].c_str());
    
    for (int test_case = 1; test_case <= T; test_case++)
    {
        input_list = getInputListFromInputstreamLine(std::cin, SPACE_CHAR);
        N = std::atoi(input_list[0].c_str());
        
        /**************************************
        * Implementation for Algorithm Problem
        ***************************************/
        std::cout << "#" << test_case << SPACE_STR;
        std::cout << std::endl;
    }
    
    #ifdef TEST
    inputFileStream.close();
    #endif
    
    return 0;
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, std::string delimiter)
{
    std::string buffer;
    std::getline(inputStream, buffer);
    return split(buffer, delimiter);
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, char delimiter)
{
    std::string buffer;
    std::getline(inputStream, buffer);
    return split(buffer, delimiter);
}

inline std::vector<std::string> split(std::string str, char delimiter)
{
    std::vector<std::string> list;
    std::stringstream ss(str);
    std::string temp;

    while (std::getline(ss, temp, delimiter))
    {
        list.push_back(temp);
    }
    
    return list;
}

inline std::vector<std::string> split(std::string s, std::string delimiter)
{
    std::vector<std::string> list;
    
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
    
        if (token.length() != 0 && token.compare(delimiter) != 0)
        {
            list.push_back(token);
        }
    
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    
    return list;
}

```
  </p>
</details>

---
## priority_queue
<details>
  <summary>Details</summary>
  <p>

```c++
class CustomType {
public:
    int id;
    int value;
    
    CustomType(int id, int value) {
        this->id = id;
        this->value = value;
    }
    
    bool operator<(const CustomType &other) const {
        return this->id == other.id ? this->value > other.value : this->id < other.id;
    }
};

priority_queue<CustomType, vector<CustomType>> priorityQueue;

priority_queue<CustomType, vector<CustomType>> priorityQueue;

priorityQueue.emplace(1, 1);
priorityQueue.emplace(1, 2);
priorityQueue.emplace(1, 3);
priorityQueue.emplace(2, 2);
priorityQueue.emplace(3, 2);
priorityQueue.emplace(4, 2);
priorityQueue.emplace(5, 2);
priorityQueue.emplace(5, 3);
priorityQueue.emplace(5, 4);
priorityQueue.emplace(5, 1);

while (!priorityQueue.empty()) {
    printf("%d %d\n", priorityQueue.top().id, priorityQueue.top().value);
    priorityQueue.pop();
}
//5 1
//5 2
//5 3
//5 4
//4 2
//3 2
//2 2
//1 1
//1 2
//1 3
```
  </p>
</details>

---
## Pair
<details>
  <summary>Details</summary>
  <p>

```c++
pair<int, char> a;

a = make_pair(1, 'c');
//a = {1, 'c'};
printf("%d %c\n", a.first, a.second);
```
  </p>
</details>

---
## Lower Bound, Upper Bound
<details>
  <summary>Details</summary>
  <p>

```c++
template<class T> int lowerBound(const std::vector<T>& list, int start, int end, int keyValue, std::function<int(const T&, const T&)> comp) {
    int lowerBound = end + 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (comp(list[mid], keyValue) >= 0) {   // list[mid] >= keyValue
            lowerBound = mid;
            end = mid - 1;
        }
        else {
        s   tart = mid + 1;
        }
    }
    
    return lowerBound;
}

template<class T> int upperBound(const std::vector<T>& list, int start, int end, int keyValue, std::function<int(const T&, const T&)> comp) {
    int upperBound = start - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (comp(list[mid], keyValue) <= 0) {   // list[mid] <= keyValue
            upperBound = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return upperBound;
}
```
  </p>
</details>

---
## Sorting
> 안정/불안정 정렬, 제자리 정렬 

[./src/lib/header/sorting_lib.h](./src/lib/header/sorting_lib.h)

### Selection Sort
<details>
  <summary>Details</summary>
  <p>
    
```c++
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
```
  </p>
</details>

### Insertion Sort
<details>
  <summary>Details</summary>
  <p>
    
```c++
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
```
  </p>
</details>

### Bubble Sort
<details>
  <summary>Details</summary>
  <p>
    
```c++
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
```
  </p>
</details>

### Quick Sort
<details>
  <summary>Details</summary>
  <p>
    
```c++
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
```
  </p>
</details>

### Merge Sort
<details>
  <summary>Details</summary>
  <p>
    
```c++
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
```
  </p>
</details>

### Heap Sort
<details>
  <summary>Details</summary>
  <p>

```c++
template<class T> void heapSort(std::vector<T>& list, int left, int right, std::function<bool(const T&, const T&)> comp) {
    Heap<T> heap(comp);
    for (int i = left; i <= right; i++) {
        heap.push(list[i]);
    }
    
    for (int i = left; i <= right; i++) {
        list[i] = heap.pop();
    }
}
```
  </p>
</details>

---
## Heap (Priority Queue)
<details>
  <summary>Details</summary>
  <p>

```c++
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

```
  </p>
</details>

