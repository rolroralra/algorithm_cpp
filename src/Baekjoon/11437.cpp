//
// Created by Shinyoung Kim on 2021/06/23.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50000
int N, M;
int LOG_N;
vector<int> adjList[MAX_N + 1];

int depth[MAX_N + 1];
int* parent[MAX_N + 1];
unsigned char isVisited[(MAX_N + sizeof(char)) / sizeof(char)];

bool isChecked(int index);
void setChecked(int index, bool value);
int lca(int leftIndex, int rightIndex);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d\n", &N);

    for (LOG_N = 0; (1 << LOG_N) < N; LOG_N++);
    int from, to;
    for (int i = 1; i <= N; i++) {
        parent[i] = (int *) calloc(LOG_N + 1, sizeof(int));
        depth[i] = -1;

        adjList[i].clear();
    }

    for (int i = 1; i < N; i++) {
        scanf("%d %d\n", &from, &to);

        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    depth[1] = 0;
    stack<int> stack;
    stack.push(1);
    setChecked(1, true);
    while (!stack.empty()) {
        int currIndex = stack.top();
        stack.pop();

        for (const auto &nextIndex : adjList[currIndex]) {
            if (isChecked(nextIndex)) {
                continue;
            }

            setChecked(nextIndex, true);
            stack.push(nextIndex);

            parent[nextIndex][0] = currIndex;
            depth[nextIndex] = depth[currIndex] + 1;

            for (int d = 0; d < LOG_N && parent[nextIndex][d] > 0; d++) {
                parent[nextIndex][d + 1] = parent[parent[nextIndex][d]][d];
            }
        }
    }

    scanf("%d\n", &M);

    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d\n", &a, &b);

        printf("%d\n", lca(a, b));
    }

    return 0;
}


int lca(int leftIndex, int rightIndex) {
    if (depth[leftIndex] < depth[rightIndex]) {
        leftIndex ^= rightIndex;
        rightIndex ^= leftIndex;
        leftIndex ^= rightIndex;
    }

    for (int d = LOG_N; d > -1 && depth[leftIndex] != depth[rightIndex]; d--) {
        if (depth[leftIndex] - depth[rightIndex] < (1 << d)) {
            continue;
        }

        leftIndex = parent[leftIndex][d];
    }

    if (leftIndex == rightIndex) {
        return leftIndex;
    }

    for (int d = LOG_N; d > -1; d--) {
        if (parent[leftIndex][d] != parent[rightIndex][d]) {
            leftIndex = parent[leftIndex][d];
            rightIndex = parent[rightIndex][d];
        }
    }

    return parent[leftIndex][0];
}

bool isChecked(int index) {
    return isVisited[index / sizeof(char)] & (1 << (index % sizeof(char)));
}

void setChecked(int index, bool value) {
    if (value) {
        isVisited[index / sizeof(char)] |= 1 << (index % sizeof(char));

    }
    else {
        isVisited[index / sizeof(char)] &= ~(1 << (index % sizeof(char)));
    }
}