//
// Created by nexledger on 13/05/2021.
//

#include "header/lower_upper_bound.h"

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

