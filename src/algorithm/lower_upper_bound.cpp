//
// Created by Shinyoung Kim on 2021/05/14.
//

#include <bits/stdc++.h>

using namespace std;

template<class T> int lowerBound(const std::vector<T>& list, int start, int end, int keyValue, std::function<int(const T&, const T&)> comp) {
    int lowerBound = end + 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (comp(list[mid], keyValue) >= 0) {   // list[mid] >= keyValue
            lowerBound = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
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

int main() {
    int arr[] = {1,1,2,2,3,3,4,4,5,6,7,7};
    std::vector<int> list;
    list.push_back(1);
    list.push_back(1);
    list.push_back(2);
    list.push_back(2);
    list.push_back(3);
    list.push_back(3);
    list.push_back(4);
    list.push_back(4);
    list.push_back(5);

    int keyValue = 2;
    int lb = lowerBound<int>(list, 0, list.end() - list.begin(), keyValue, [](int l, int r)->int{return l - r;});
    int ub = upperBound<int>(list, 0, list.end() - list.begin(), keyValue, [](int l, int r)->int{return l - r;});
    printf("keyValue: %d, lowerBound: %d, upperBound: %d\n", keyValue, lb, ub);

    return 0;
}

