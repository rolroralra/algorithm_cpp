//
// Created by shyoung.kim on 2021-05-12.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
#define MAX_K 100

int T, N, K;

int countArr[MAX_K + 1];

int backtracking(int number, int count);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d\n", &N, &K);

        memset(countArr, 0x00, (K + 1) * sizeof(int));

        for (int i = 0; i < N; i++) {
            int number;
            scanf("%d ", &number);
            countArr[number]++;
        }

        int result = backtracking(0, 3);

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}

int backtracking(int number, int count) {
    if (count == 0) {
        return countArr[number] * number;
    }


    int result = 0;
    for (int nextNumber = number + 1; nextNumber <= K; nextNumber++) {
        result = max(result, countArr[number] * number + backtracking(nextNumber, count - 1));
    }

    return result;
}
