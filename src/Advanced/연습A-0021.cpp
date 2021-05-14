//
// Created by nexledger on 13/05/2021.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

int T, N;
int arr[MAX_N];
vector<int> list;
int main() {

    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d\n", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d ", &arr[i]);
        }

        vector<int> list;
        for (int i = 0; i < N; i++) {
            int index = lower_bound(list.begin(), list.end(), arr[i]) - list.begin();
            if (index >= list.size()) {
                list.push_back(arr[i]);
            }
            else {
                list[index] = arr[i];
            }
        }

        int result = list.size();

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}

