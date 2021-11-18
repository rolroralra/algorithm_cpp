## Template Source
<details>
  <summary>Details</summary>
  <p>
    
    
```c++
#include <bits/stdc++.h>

using namespace std;

int T, N, K;

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d\n", &N, &K);

        int result = 0;

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}    
```
  </p>
</details>
    
<details>
  <summary>Details - std::ios::sync_with_stdio(false);</summary>
  <p>   

```c++
#include <bits/stdc++.h>

using namespace std;

int T, N, K;

int main() {
    std::ios::sync_with_stdio(false); // 최초 1회 
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifdef TEST
    std::ifstream inputFileStream;
    inputFileStream.open("../src/sample_input.txt", std::ios_base::in);
    if (inputFileStream.is_open())
    {
        std::cin.rdbuf(inputFileStream.rdbuf()); // swap
    }
    #endif
    
    cin >> T; 

    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N >> K;
        
        int result = 0;

        cout << "#" << test_case << " " << result << endl;
    }

    return 0;
}    
```
  </p>
</details>
    
<details>
  <summary>TLDR;</summary>
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
## DFS, BFS (Depth First Search, Breadth First Search)
<details>
  <summary>Details</summary>
  <p>

```c++
void dfsByRecursive(int currIndex, bool isRoot) {
    isVisited[currIndex] = true;
    printf("%d ", currIndex);

    for (const auto &nextIndex : adjList[currIndex]) {
        if (isVisited[nextIndex]) {
            continue;
        }

        dfsByRecursive(nextIndex, false);
    }
    
    isCompleted[currIndex] = true;

    if (isRoot) {
        printf("\n");
    }
}
void dfsByStack(int startIndex) {
    stack<int> stack;

    stack.push(startIndex);
    while(!stack.empty()) {
        int currIndex = stack.top();
        stack.pop();

        if (isVisited[currIndex]) {
            continue;
        }

        isVisited[currIndex] = true;
        printf("%d ", currIndex);

        for (const auto &nextIndex : adjList[currIndex]) {
            if (isVisited[nextIndex]) {
                continue;
            }

            stack.push(nextIndex);
        }
    }

    printf("\n");
}

void bfsByQueue(int startIndex) {
    queue<int> queue;

    isVisited[startIndex] = true;
    queue.push(startIndex);
    while(!queue.empty()) {
        int currIndex = queue.front();
        queue.pop();

        printf("%d ", currIndex);

        for (const auto &nextIndex : adjList[currIndex]) {
            if (isVisited[nextIndex]) {
                continue;
            }

            isVisited[nextIndex] = true;
            queue.push(nextIndex);
        }

//        int size = adjList[currIndex].size();
//        for (int i = size - 1; i > -1; i--) {
//            int nextIndex = adjList[currIndex][i];
//
//            if (isVisited[nextIndex]) {
//                continue;
//            }
//
//            isVisited[nextIndex] = true;
//            queue.push(nextIndex);
//        }
    }

    printf("\n");
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
    
---
## Matrix
<details>
    <summary>Details</summary>
    <p>

```c++
class Matrix {
public:
    int size;
    vector<vector<long long>> matrix;

    Matrix(int n): size(n) {
        matrix.resize(n, vector<long long>(n, 0));
    }

    Matrix operator*(const Matrix& right) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result.matrix[i][j] += matrix[i][k] * right.matrix[k][j];
                }
            }
        }
        return result;
    }

    static Matrix id(int n) {
        Matrix id(n);
        for (int i = 0; i < n; i++) {
            id.matrix[i][i] = 1;
        }
        return id;
    }

    static Matrix exponent(Matrix m, int power) {
        if (power == 0) {
            return Matrix::id(m.size);
        }

        Matrix half = Matrix::exponent(m, power / 2);
        return power % 2 == 0 ? half * half : half * half * m;
    }

    Matrix exponent(int power) const {
        if (power == 0) {
            return Matrix::id(size);
        }

        Matrix half = this->exponent(power / 2);

        return power % 2 == 0 ? half * half : half * half * (*this);
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%ld ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}
```
  </p>
</details>
    
---
## Eratosthenes Sieve (에라토스테네스의 체)
    
<details>
    <summary>Details</summary>
    <p>
      
```cpp
#include <bits/stdc++.h>

#define MAX_N 1000
int T, N, K;

unsigned char sieve[(MAX_N + sizeof(char) - 1) / sizeof(char)];
bool isPrime(int index);
bool isComposite(int index);
void setPrime(int index);
void setComposite(int index);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d\n", &N);
    memset(sieve, (1 << (sizeof(char) << 3)) - 1, sizeof(sieve));

    setComposite(0);
    setComposite(1);
    for (int i = 2; i * i <= MAX_N; i++) {
        if (isComposite(i)) {
            continue;
        }

        for (int j = i * i; j <= MAX_N; j += i) {
            setComposite(j);
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d ", &input);

        if (isPrime(input)) {
            result++;
        }
    }

    printf("%d\n", result);

    return 0;
}

bool isPrime(int index) {
    return sieve[index / 8] & (1 << (index % 8));
//    return arr[index >> 3] & (1 << (index & 7));
}

bool isComposite(int index) {
    return !isPrime(index);
//    return arr[index / 8]
}

void setPrime(int index) {
    sieve[index / 8] |=  1 << (index % 8);
}

void setComposite(int index) {
    sieve[index / 8] &= ~(1 << (index % 8));
}
```
  </p>
</details>

---
## SegmentTree
<details>
    <summary>Details</summary>
    <p>

```c++
class SegmentTree {
    int *tree[3];
    int treeSize;
    int originalDataSize;

public:
    void update(int index, int value) {
        update(index, value, 0, 0, originalDataSize - 1);
    }

    int queryMax(int left, int right) {
        return queryMax(left, right, 0, 0, originalDataSize - 1);
    }

    int queryMin(int left, int right) {
        return queryMin(left, right, 0, 0, originalDataSize - 1);
    }

    int querySum(int left, int right) {
        return querySum(left, right, 0, 0, originalDataSize - 1);
    }

    SegmentTree(int size) : originalDataSize(size){
        for (treeSize = 1; treeSize < size; treeSize <<= 1);
        treeSize = treeSize * 2 - 1;

        tree[0] = (int*) calloc(treeSize, sizeof(int));
        tree[1] = (int*) calloc(treeSize, sizeof(int));
        tree[2] = (int*) calloc(treeSize, sizeof(int));

    }

private:
    void update(int index, int value, int node, int nodeLeft, int nodeRight) {
        if (index < nodeLeft || nodeRight < index) {
            return;
        }

        if (nodeLeft == nodeRight) {
            tree[0][node] = value;
            tree[1][node] = value;
            tree[2][node] = value;
            return;
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        update(index, value, leftNode, nodeLeft, nodeMid);
        update(index, value, rightNode, nodeMid + 1, nodeRight);

        tree[0][node] = max(tree[0][leftNode], tree[0][rightNode]);
        tree[1][node] = min(tree[1][leftNode], tree[1][rightNode]);
        tree[2][node] = tree[2][leftNode] + tree[2][rightNode];
    }

    int queryMax(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) {
            return INT32_MIN;
        }

        if (left <= nodeLeft && nodeRight <= right) {
            return tree[0][node];
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        return max(queryMax(left, right, leftNode, nodeLeft, nodeMid), queryMax(left, right, rightNode, nodeMid + 1, nodeRight));
    }

    int queryMin(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) {
            return INT32_MAX;
        }

        if (left <= nodeLeft && nodeRight <= right) {
            return tree[1][node];
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        return min(queryMin(left, right, leftNode, nodeLeft, nodeMid), queryMin(left, right, rightNode, nodeMid + 1, nodeRight));
    }

    int querySum(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) {
            return 0;
        }

        if (left <= nodeLeft && nodeRight <= right) {
            return tree[2][node];
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        int nodeMid = (nodeLeft + nodeRight) / 2;

        return querySum(left, right, leftNode, nodeLeft, nodeMid) + querySum(left, right, rightNode, nodeMid + 1, nodeRight);
    }
};
```
  </p>
</details>

---
## BinaryIndexTree
<details>
    <summary>Details</summary>
    <p>

```c++
class BinaryIndexTree {
private:
    int* tree;
    int originalDataSize;
    int baseIndex;
    int treeSize;
    static const int ROOT_INDEX = 0;

    bool checkBaseIndex(int index) {
        return index >= 0 && index < originalDataSize;
    }
    
    void refresh(int node) {
        if (node >= baseIndex) {
            return;
        }

        int leftNode = node * 2 + 1;
        int rightNode = leftNode + 1;
        tree[node] = min(tree[leftNode], tree[rightNode]);
    }
public:
    BinaryIndexTree(int *arr, int size) : BinaryIndexTree(size) {
        for (int i = 0; i < size; i++) {
            update(i, arr[i]);
        }
    }

    BinaryIndexTree(int size) : originalDataSize(size) {
        for (baseIndex = 1; baseIndex < N; baseIndex<<=1);
        treeSize = baseIndex * 2 - 1;
        baseIndex--;

        tree = (int*) calloc(treeSize, sizeof(int));
    }

    void update(int index, int value) {
        if (!checkBaseIndex(index))
            return;

        int node = baseIndex + index;

        tree[node] = value;

        while (node > ROOT_INDEX) {
            node = (node - 1) / 2;
            refresh(node);
        }
    }

    int query(int left, int right) {
        if (!checkBaseIndex(left) || !checkBaseIndex(right)) {
            return INT32_MAX;
        }

        int leftNode = baseIndex + left;
        int rightNode = baseIndex + right;

        int result = INT32_MAX;
        while(leftNode < rightNode) {
            if (leftNode % 2 == 0) {
                result = min(result, tree[leftNode++]);
            }

            if (rightNode % 2 == 1) {
                result = min(result, tree[rightNode--]);
            }

            leftNode = (leftNode - 1) / 2;
            rightNode = (rightNode - 1) / 2;
        }

        if (leftNode == rightNode) {
            result = min(result, tree[leftNode]);
        }

        return result;
    }
};
```
  </p>
</details>

---
## FenwickTree
<details>
  <summary>Details</summary>
  <p>

```c++
class FenwickTree {
public:
    FenwickTree(int size) {
        FenwickTree(size + 1, true);
    }

    FenwickTree(int size, bool isZeroBaseIndex) : size(size + 1), isZeroBaseIndex(isZeroBaseIndex){
        fenwickTree = static_cast<long long int *>(calloc(size + 1, sizeof(long long)));
    }

    void update(int index, long long diffValue) {
        if (isZeroBaseIndex) {
            index++;
        }

        _update(index, diffValue);
    }

    long long query(int startInclusive, int endInclusive) {
        if (isZeroBaseIndex) {
            startInclusive++;
            endInclusive++;
        }

        return _querySum(endInclusive) - _querySum(startInclusive - 1);
    }
private:
    int size;
    long long *fenwickTree;
    bool isZeroBaseIndex;

    void _update(int index, long long diffValue) {
        while (index < size) {
            fenwickTree[index] += diffValue;

            index += index & (-index);
        }
    }

    long long _querySum(int index) {
        long long result = 0;
        while(index > 0) {
            result += fenwickTree[index];

            index &= (index - 1);
//            index -= index & (-index);
        }

        return result;
    }
};
```
  </p>
</details>

---
## Articulation Point (단절점)
<details>
    <summary>Details</summary>
    <p>

```c++
#include <bits/stdc++.h>

using namespace std;

#define MAX_V 10000

int V, E;
vector<int> *adjList;
int isVisited[MAX_V + 1];
int serialNumber = 0;
bool isArticulationPoint[MAX_V + 1];
int countOfArticulationPoints = 0;

int dfs(int currIndex, bool isRoot, int* visit);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d %d\n", &V, &E);

    adjList = (vector<int> *) calloc(V + 1, sizeof(vector<int>));
    memset(isVisited, 0x00, sizeof(isVisited));

    for (int i = 0; i < E; i++) {
        int from, to;
        scanf("%d %d\n", &from, &to);

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }


    for (int v = 1; v <= V; v++) {
        if (!isVisited[v]) {
            dfs(v, true, isVisited);
        }
    }

    printf("%d\n", countOfArticulationPoints);
    for (int v = 1; v <= V; v++) {
        if(!isArticulationPoint[v]) {
            continue;
        }

        printf("%d ", v);
    }
    printf("\n");

    return 0;
}

int dfs(int currIndex, bool isRoot, int* visit) {
    visit[currIndex] = ++serialNumber;

    int returnValue = visit[currIndex];

    int spanningTreeChildCount = 0;
    for (const auto &nextIndex : adjList[currIndex]) {
        if (!visit[nextIndex]) {
            spanningTreeChildCount++;

            int minSerialNumberFromNextIndex = dfs(nextIndex, false, visit);
            returnValue = min(returnValue, minSerialNumberFromNextIndex);

            if (!isRoot && minSerialNumberFromNextIndex >= visit[currIndex]) {
                countOfArticulationPoints += isArticulationPoint[currIndex] ? 0 : 1;
                isArticulationPoint[currIndex] = true;
            }
        }
        else {
            returnValue = min(returnValue, visit[nextIndex]);
        }
    }

    if (isRoot && spanningTreeChildCount >= 2) {
        countOfArticulationPoints += isArticulationPoint[currIndex] ? 0 : 1;
        isArticulationPoint[currIndex] = true;
    }

    return returnValue; // minSerialNumberFromCurrIndex
}
```
  </p>
</details>

---
## Articulation Edge (단절선)
<details>
    <summary>Details</summary>
    <p>

```c++
#include <bits/stdc++.h>

using namespace std;

#define MAX_V 100000

int V, E;
vector<int> *adjList;
int isVisited[MAX_V + 1];
int serialNumber = 0;

vector<pair<int, int>> articulationEdgeList;

int dfs(int currIndex, int prevIndex, int* visitCount);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d %d\n", &V, &E);

    adjList = (vector<int> *) calloc(V + 1, sizeof(vector<int>));
    memset(isVisited, 0x00, sizeof(isVisited));
    articulationEdgeList.clear();

    for (int i = 0; i < E; i++) {
        int from, to;
        scanf("%d %d\n", &from, &to);

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }


    for (int v = 1; v <= V; v++) {
        if (!isVisited[v]) {
            dfs(v, -1, isVisited);
        }
    }

    sort(articulationEdgeList.begin(), articulationEdgeList.end());

    printf("%lu\n", articulationEdgeList.size());
    for (const auto &item : articulationEdgeList) {
        printf("%d %d\n", item.first, item.second);
    }
    return 0;
}

int dfs(int currIndex, int prevIndex, int* visitCount) {
    visitCount[currIndex] = ++serialNumber;

    int returnValue = visitCount[currIndex];

    for (const auto &nextIndex : adjList[currIndex]) {
        if (nextIndex == prevIndex) {
            continue;
        }

        if (!visitCount[nextIndex]) {

            int minSerialNumberFromNextIndex = dfs(nextIndex, currIndex, visitCount);
            returnValue = min(returnValue, minSerialNumberFromNextIndex);

            if (minSerialNumberFromNextIndex > visitCount[currIndex]) {
                int a = currIndex;
                int b = nextIndex;

                if (a > b) {
                    a ^= b;
                    b ^= a;
                    a ^= b;
                }

                articulationEdgeList.emplace_back(a, b);
            }

        }
        else {
            returnValue = min(returnValue, visitCount[nextIndex]);
        }
    }

    return returnValue; // minSerialNumberFromCurrIndex
}
```
  </p>
</details>

---
## MST (Minimal Spanning Tree)
<details>
  <summary>Details</summary>
  <p>

```c++
#include <bits/stdc++.h>

using namespace std;

#define MAX_V 10000
int V, E;

void primAlgorithm() ;
vector<pair<int, int>>* adjList;
bool isVisited[MAX_V + 1];

void kruskalAlgorithm() ;
vector<tuple<int, int, int>> edgeList;
int parent[MAX_V + 1];
int find(int index);
void merge(int leftIndex, int rightIndex);

class comp {
public:
    bool operator() (const pair<int, int> &left, const pair<int, int> &right) {
        return left.second > right.second;
    }
};

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d %d\n", &V, &E);

    adjList = static_cast<vector<pair<int, int>> *>(calloc(V + 1, sizeof(vector<pair<int, int>>)));

    for (int i = 1; i <= V; i++) {
        parent[i] = -1;
    }


    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d\n", &a, &b, &c);

        adjList[a].push_back(make_pair(b, c));
        adjList[b].emplace_back(a, c);

        edgeList.push_back(make_tuple(a, b, c));
    }

    primAlgorithm();
//    kruskalAlgorithm();

    return 0;
}

// Prim's Algorithm
void primAlgorithm() {
    int primAlgorithmResult = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.emplace(1, 0);
    while (!pq.empty()) {
        int currIndex = pq.top().first;
        int currEdgeLength = pq.top().second;
        pq.pop();

        if (isVisited[currIndex]) {
            continue;
        }

        isVisited[currIndex] = true;
        primAlgorithmResult += currEdgeLength;

        for (const auto &nextInfo : adjList[currIndex]) {
            int nextIndex = nextInfo.first;
            int nextEdgeLength = nextInfo.second;

            if (isVisited[nextIndex]) {
                continue;
            }

            pq.emplace(nextIndex, nextEdgeLength);
        }
    }

    printf("%d\n", primAlgorithmResult);
}

// Kruskal's Algorithm
void kruskalAlgorithm() {
    sort(edgeList.begin(), edgeList.end(), [](const tuple<int, int, int> &left, const tuple<int, int, int> &right)->bool{return get<2>(left) < get<2>(right);});

    int kruskalALgorithmResult = 0;
    for (int i = 0; i < E; i++) {
        int a = get<0>(edgeList[i]);
        int b = get<1>(edgeList[i]);
        int c = get<2>(edgeList[i]);

        if(find(a) == find(b)) {
            continue;
        }

        kruskalALgorithmResult += c;
        merge(a, b);
    }

    printf("%d\n", kruskalALgorithmResult);
}

// Find
int find(int index) {
    if (parent[index] < 0) {
        return index;
    }

    // Path Comprehension
    return parent[index] = find(parent[index]);
}

// Union
void merge(int leftIndex, int rightIndex) {
    int leftRootIndex = find(leftIndex);
    int rightRootIndex = find(rightIndex);

    if (leftRootIndex == rightRootIndex) {
        return;
    }

    if (parent[leftRootIndex] > parent[rightRootIndex]) {
        leftRootIndex ^= rightRootIndex;
        rightRootIndex ^= leftRootIndex;
        leftRootIndex ^= rightRootIndex;
    }

    parent[leftRootIndex] += parent[rightRootIndex];
    parent[rightRootIndex] = leftRootIndex;
}
```
  </p>
</details>

---
## Topological Sort (위상정렬)

<details>
  <summary>Details</summary>
  <p>

### By using DFS with post-order
```c++
vector<int> topologicalSortByDFS() {
    vector<int> sortedList;
    stack<int> sortedStack;
    
    for (int i = 1; i <= N; i++) {
        if(inDegree[i] == 0) {
            _topologicalSortByDFS(i, sortedStack);
        }
    }
    
    while (!sortedStack.empty()) {
        sortedList.push_back(sortedStack.top());
        sortedStack.pop();
    }
    
    return sortedList;
}
void _topologicalSortByDFS(int currIndex, stack<int> &sortedStack) {
    isVisited[currIndex] = true;

    for (const auto &nextIndex : adjList[currIndex]) {
        if (!isVisited[nextIndex]) {
            _topologicalSortByDFS(nextIndex, sortedStack);
        }
    }

    isCompleted[currIndex] = true;
    
    sortedStack.push(currIndex);
}
```

### By using BFS with in-degree
```c++
void topologicalSortByBFS() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int currIndex = q.front();
        q.pop();
        
        // Visit CurrIndex Process

        // Next Child Node Process
        for (auto &nextIndex : adjList[currIndex]) {
            if ((--inDegree[nextIndex]) == 0) {
                q.push(nextIndex);
            }
        }
    }
}
```
  </p>
</details>
