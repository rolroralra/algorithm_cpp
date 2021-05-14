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

using namespace std;

/*************************************************************************/
/* Libarary Function
/*************************************************************************/
std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, char delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, std::string delimiter);
std::vector<std::string> getInputList();


template<class T> void selectionSort(std::vector<T>& list, int size, bool(*comp)(T, T));
template<class T> void insertionSort(std::vector<T>& list, int size, bool(*comp)(T, T));
template<class T> void bubbleSort(std::vector<T>& list, int size, bool(*comp)(T, T));
template<class T> void quickSort_(std::vector<T>& list, int left, int right, std::function<bool(T, T)> comp);
template<class T> void quickSort(std::vector<T>& list, int size, std::function<bool(T, T)> comp);

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

#define MAX_N 50

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


int T;
int N;
vector<int> list(MAX_N);

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

        input_list = getInputList();
        for (int i = 0; i < N; i++) {
            list[i] = std::atoi(input_list[i].c_str());
        }

        //std::sort()
        mergeSort<int>(list, 0, N - 1, [](int t1, int t2)->bool { return t1 < t2; });

        std::cout << "#" << test_case;

        for_each(list.begin(), list.begin() + N, [](int t)->void {std::cout << SPACE_STR << t; });

        std::cout << std::endl;

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
