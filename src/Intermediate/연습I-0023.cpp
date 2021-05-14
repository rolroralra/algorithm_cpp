#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <limits>
#include <functional>
#include <algorithm>
//#include "lib/header/string_lib.h"

//#define TEST
//#define STRING_TRIM
#define SORTING_ALGORITHM

using namespace std;

/*************************************************************************/
/* Libarary Function
/*************************************************************************/
std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, char delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, std::string delimiter);
std::vector<std::string> getInputList();

#ifdef SORTING_ALGORITHM
template<class T> void selectionSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp);
template<class T> void insertionSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp);
template<class T> void bubbleSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp);
template<class T> void quickSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp);
template<class T> void mergeSort(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp);
#endif

int parseInt(std::string str);

#ifdef STRING_TRIM
void ltrim(std::string& s);
void rtrim(std::string& s);
void trim(std::string& s);
std::string ltrim_copy(std::string s);
std::string rtrim_copy(std::string s);
std::string trim_copy(std::string s);
#endif
/*************************************************************************/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define SPACE_STR " "
#define STAR_STR "*"
#define SPACE_CHAR ' '
#define STAR_CHAR '*'

#define MAX_N 20

template<class T> inline void swap(T& t1, T& t2) {
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

#ifdef SORTING_ALGORITHM
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
#endif

int T;
int N, K;
vector<vector<int>> list(MAX_N, vector<int>(MAX_N));

int main(int argc, char** argv) {

#ifdef TEST
    string filePath = "sample_input.txt";
    // read File
    ifstream inputFileStream;
    inputFileStream.open(filePath, ios_base::in);
    //ifstream openFile(filePath);
    if (inputFileStream.is_open()) {
        std::cin.rdbuf(inputFileStream.rdbuf());  // swap
    }
#endif

    string input;
    vector<string> input_list;

    //std::getline(std::cin, input);
    //input_list = split(input, SPACE_STR);
    input_list = getInputList();
    T = std::atoi(input_list[0].c_str());

    for (int test_case = 1; test_case <= T; test_case++) {
        /**************************************
        * Implementation for Algorithm Problem
        ***************************************/
        input_list = getInputList();
        N = std::atoi(input_list[0].c_str());
        K = std::atoi(input_list[1].c_str());


        for (int i = 0; i < N; i++) {
            input_list = getInputList();
            for (int j = 0; j < N; j++) {
                list[i][j] = std::atoi(input_list[j].c_str());
            }
        }

        std::function<bool(std::vector<int>, std::vector<int>)> comp = [&](vector<int> list1, vector<int> list2)-> bool {
            return list1[K - 1] < list2[K - 1];
        };

        //selectionSort<vector<int>>(list, 0, N - 1, comp);
        //insertionSort<vector<int>>(list, 0, N - 1, comp);
        bubbleSort<vector<int>>(list, 0, N - 1, comp);
        //quickSort<vector<int>>(list, 0, N - 1, comp);
        //mergeSort<vector<int>>(list, 0, N - 1, comp);



        std::cout << "#" << test_case << std::endl;

        for_each(list.begin(), list.begin() + N, [](vector<int> v)->void {
            for_each(v.begin(), v.begin() + N, [](int i)->void {
                std::cout << i << " ";
            });
            std::cout << std::endl;
        });

    }

#ifdef TEST
    inputFileStream.close();
#endif

    return 0;
}



inline int parseInt(std::string str) {
    return std::atoi(str.c_str());
}

inline std::vector<std::string> getInputList() {
    return getInputListFromInputstreamLine(std::cin, SPACE_STR);
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, std::string delimiter) {
    std::string buffer;
    std::getline(inputStream, buffer);
    return split(buffer, delimiter);
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, char delimiter) {
    std::string buffer;
    std::getline(inputStream, buffer);
    return split(buffer, delimiter);
}

inline std::vector<string> split(std::string str, char delimiter) {
    vector<string> list;
    stringstream ss(str);
    string temp;

    while (std::getline(ss, temp, delimiter)) {
        list.push_back(temp);
    }

    return list;
}

inline std::vector<string> split(std::string s, std::string delimiter) {
    std::vector<string> list;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);

        if (token.length() != 0 && token.compare(delimiter) != 0) {
            list.push_back(token);
        }

        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);

    return list;
}
