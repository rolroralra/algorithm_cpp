//
// Created by shyoung.kim on 2021-03-19.
//

#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

#define MAX_K 100
#define MAX_N 1000
#define MAX_M 10000

int T, K, N, M;

int isConnected[MAX_N + 1][MAX_N + 1];
bool isVisited[MAX_N + 1];
int countVisit[MAX_N + 1];
int startIndexArr[MAX_K];
int main(int argc, char** argv) {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d %d", &K, &N, &M);

        for (int i = 0; i < K; i++) {
            scanf("%d", &startIndexArr[i]);
        }

        memset(isConnected, 0x00, sizeof(isConnected));
        memset(countVisit, 0x00, sizeof(int) * (N + 1));

        for (int i = 0; i < M; i++){
            int src, dst;
            scanf("%d %d", &src, &dst);
            isConnected[src][dst] = true;
        }


        queue<int> queue;
        for (int i = 0; i < K; i++) {

            memset(isVisited, 0x00, sizeof(bool) * (N + 1));

            queue.push(startIndexArr[i]);
            isVisited[startIndexArr[i]] = true;
            countVisit[startIndexArr[i]]++;
            while (!queue.empty()) {
                int currIndex = queue.front();
                queue.pop();

                for (int nextIndex = 1; nextIndex <= N; nextIndex++) {
                    if (isVisited[nextIndex] || !isConnected[currIndex][nextIndex]) {
                        continue;
                    }

                    isVisited[nextIndex] = true;
                    countVisit[nextIndex]++;
                    queue.push(nextIndex);
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= N; i++) {
            if (countVisit[i] == K) {
                result++;
            }
        }

        printf("#%d %d\n", test_case, result);

    }

    return 0;
}

