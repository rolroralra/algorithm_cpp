//
// Created by shyoung.kim on 2021-04-01.
//

#include <bits/stdc++.h>

using namespace std;

void dfs();
void bfs();

#define MAX_E 500
#define MAX_V 100

int T, V, E, S;
bool adjMatrix[MAX_V + 1][MAX_V + 1];
bool isVisited[MAX_V + 1];

void dfs() {
    stack<int> stack;
    memset(isVisited, 0x00, sizeof(isVisited));

    int visitCount = 0;
    stack.push(S);
    while(!stack.empty()) {
        int currentIndex = stack.top();
        stack.pop();

        if (isVisited[currentIndex]) {
            continue;
        }

        isVisited[currentIndex] = true;
        printf("%d", currentIndex);
        visitCount++;

        if (visitCount == V) {
            break;
        } else {
            printf(" ");
        }

        for (int nextIndex = V; nextIndex > -1; nextIndex--) {
            if (!isVisited[nextIndex] && adjMatrix[currentIndex][nextIndex]) {
                stack.push(nextIndex);
            }
        }
    }
}

void bfs() {
    queue<int> queue;
    memset(isVisited, 0x00, sizeof(isVisited));


    int visitCount = 0;
    isVisited[S] = true;
    queue.push(S);
    while (!queue.empty()) {
        int currentIndex = queue.front();
        queue.pop();

        printf("%d", currentIndex);
        visitCount++;

        if (visitCount == V) {
            break;
        } else {
            printf(" ");
        }

        for (int nextIndex = 1; nextIndex <= V; nextIndex++) {
            if (!isVisited[nextIndex] && adjMatrix[currentIndex][nextIndex]) {
                isVisited[nextIndex] = true;
                queue.push(nextIndex);
            }
        }
    }
}

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d %d", &V, &E, &S);


        memset(adjMatrix, 0x00, sizeof(adjMatrix));

        for (int i = 0; i < E; i++) {
            int src, dst;
            scanf("%d %d", &src, &dst);
            adjMatrix[src][dst] = true;
            adjMatrix[dst][src] = true;
        }

        printf("#%d ", test_case);
        dfs();
        printf("\n");
        bfs();
        printf("\n");

    }

    return 0;
}
