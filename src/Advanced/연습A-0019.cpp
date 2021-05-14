//
// Created by shyoung.kim on 2021-05-12.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
#define MAX_M 500
#define MAX_K 10000

int T, N, M, K;

char cards[MAX_N];
vector<vector<pair<int, char>>> adjList;

int cache[MAX_M + 1][MAX_N + 1];

int backtracking(int currIndex, int count);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d\n", &N);

        for (int i = 0; i < N; i++) {
            scanf("%c ", &cards[i]);
        }

        scanf("%d %d\n", &M, &K);

        adjList.clear();
        for (int i = 0; i <= M; i++) {
            vector<pair<int, char>> v;
            adjList.push_back(v);

            for (int j = 0; j <= N; j++) {
                cache[i][j] = -1;
            }
        }

        for (int i = 0; i < K; i++) {
            int src, dst;
            char input;

            scanf("%d %d %c\n", &src, &dst, &input);
            adjList[src].push_back(make_pair(dst, input));
            adjList[dst].push_back(make_pair(src, input));
        }

        int result = backtracking(1, N);

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}

int backtracking(int currIndex, int count) {
    if (cache[currIndex][count] != -1) {
        return cache[currIndex][count];
    }

    if (count == 0) {
        return cache[currIndex][count] = 0;
    }

    int result = 0;

    for (auto roadInfo : adjList[currIndex]) {
        int nextIndex = roadInfo.first;
        char color = roadInfo.second;

        if (cards[N - count] == color) {
            result = max(result, 10 + backtracking(nextIndex, count - 1));
        } else {
            result = max(result, backtracking(nextIndex, count - 1));
        }
    }

    return cache[currIndex][count] = result;
}

