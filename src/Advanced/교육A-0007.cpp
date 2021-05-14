//
// Created by shyoung.kim on 2021-04-01.
//

#include <bits/stdc++.h>

using namespace std;

void backtracking(int currentLength, int currentValueSum, int *values, int size);

#define MAX_N 3000

int T, N;
int values[MAX_N + 1];
int cache[MAX_N + 1];
int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d", &N);

        int memorySize = sizeof(int) * (N + 1);
        memset(values, 0x00, memorySize);
        memset(cache, 0x00, memorySize);

        for (int i = 1; i <= N; i++) {
            scanf("%d", &values[i]);
        }


        backtracking(0, 0, values, N);

        int result = cache[N];

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}

void backtracking(int currentLength, int currentValueSum, int *values, int size) {
    int remainLength = size - currentLength;

    for (int length = 1; length <= remainLength; length++) {
        int nextLength = currentLength + length;
        int nextValueSum = currentValueSum + values[length];
        if (cache[nextLength] >= nextValueSum) {
            continue;
        }

        cache[nextLength] = nextValueSum;

        if (nextLength < size) {
            backtracking(nextLength, nextValueSum, values, size);
        }
    }
}





