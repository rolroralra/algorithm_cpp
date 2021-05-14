//
// Created by shyoung.kim on 2021-05-12.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500000
#define MOD 1000000007

int T, N;

int topHeight[MAX_N];
stack<pair<int, int>> stk;

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d\n", &N);

        int result = 0;

        for (int radioIndex = 0; radioIndex < N; radioIndex++) {
            scanf("%d ", &topHeight[radioIndex]);

            while (!stk.empty()) {
                int receiveHeight = stk.top().first;
                int receiveIndex = stk.top().second;
                if (topHeight[radioIndex] <= receiveHeight) {
                    result = (result + receiveIndex) % MOD;
                    break;
                } else {
                    stk.pop();
                }
            }

            stk.push({topHeight[radioIndex], radioIndex + 1});
        }

        while (!stk.empty()) {
            stk.pop();
        }

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}