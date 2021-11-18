//
// Created by nexledger on 13/05/2021.
//

#ifndef ALGORITHM_CPP_LOWER_UPPER_BOUND_H
#define ALGORITHM_CPP_LOWER_UPPER_BOUND_H

template<class T> int lowerBound(const std::vector<T>& list, int start, int end, int keyValue, std::function<int(const T&, const T&)> comp);
template<class T> int upperBound(const std::vector<T>& list, int start, int end, int keyValue, std::function<int(const T&, const T&)> comp);

#endif //ALGORITHM_CPP_LOWER_UPPER_BOUND_H
