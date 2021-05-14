//
// Created by shyoung.kim on 2021-04-13.
//

template<class T>
int binarySearch(int begin, int end, T* src, T value) {
    if (begin > end) {
        return -(begin + 1);
    }

    int index = (begin + end) / 2;

    if (src[index] == value) {
        return index;
    } else if (src[index] < value) {
        return binarySearch(index + 1, end, src, value);
    } else {
        return binarySearch(begin, index - 1, src, value);
    }
}