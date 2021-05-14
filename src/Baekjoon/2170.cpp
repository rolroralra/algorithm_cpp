//
// Created by shyoung.kim on 2021-02-18.
//
#include <iostream>

using namespace std;

#define MAX_N 1000000

int N;
int main(int argc, char** argv) {

    cin >> N;
    pair<int, int> *arr = new pair<int, int>[N];

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        arr[i] = make_pair(x, y);
    }

    qsort(arr, N, sizeof(pair<int, int>), [](pair<int, int> &left, pair<int, int> &right)->int{
       return left.first == right.first ? left.second - right.second : left.first - right.first;
    });

    for (int i = 0; i < N; i++) {
        cout << arr[i].first << ", " << arr[i].second << endl;
    }


}