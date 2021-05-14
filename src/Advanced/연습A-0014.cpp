//
// Created by shyoung.kim on 2021-04-12.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_W 1500
#define MAX_H 1500
#define DIRECTION_NUM 4

int T, W, H;
char graph[MAX_H][MAX_W];

int dx[DIRECTION_NUM] = {0, 1, 0, -1};
int dy[DIRECTION_NUM] = {1, 0, -1, 0};

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d\n", &W, &H);

        int start;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%c", &graph[i][j]);

                switch (graph[i][j]) {
                    case 'S':
                        start = i * W + j;
                        break;
                }
            }
            scanf("\n");
        }

        queue<pair<int, int>> queue;
        queue.emplace(start, 1);
        int result = -1;
        while (!queue.empty()) {
            pair<int, int> currentInfo = queue.front();
            queue.pop();

            int currRow = currentInfo.first / W;
            int currCol = currentInfo.first % W;
            int currCount = currentInfo.second;

            for (int i = 0; i < DIRECTION_NUM; i++) {
                int nextRow = currRow + dx[i];
                int nextCol = currCol + dy[i];

                if (nextRow < 0 || nextRow >= H || nextCol < 0 || nextCol >= W) {
                    continue;
                }

                if  (graph[nextRow][nextCol] == 'O') {
                    graph[nextRow][nextCol] = 'X';
                    queue.emplace(nextRow * W + nextCol, currCount + 1);
                } else if (graph[nextRow][nextCol] == 'E') {
                    result = currCount;
                    break;
                }
            }

            if (result != -1) {
                break;
            }
        }

        printf("#%d %d\n", test_case, result);

    }

    return 0;
}