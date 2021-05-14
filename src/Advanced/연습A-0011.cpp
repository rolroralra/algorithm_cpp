//
// Created by shyoung.kim on 2021-03-09.
//

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 1000

int T, N, M, X;

void dijkstra(int** adjMatrix, long* dist, int startIndex, int size);

int ***adjMatrix = (int***) calloc(2, sizeof(int**));
long **dist = (long **) calloc(3, sizeof(long *));
int main(int argc, char** argv) {
    freopen("../src/sample_input.txt", "r", stdin);

    adjMatrix[0] = (int **) calloc(MAX_N + 1, sizeof(int*));
    adjMatrix[1] = (int **) calloc(MAX_N + 1, sizeof(int*));
    dist[0] = (long *) calloc(MAX_N + 1, sizeof(long));
    dist[1] = (long *) calloc(MAX_N + 1, sizeof(long));
    dist[2] = (long *) calloc(MAX_N + 1, sizeof(long));
    for (int i = 1; i <= MAX_N; i++) {
        adjMatrix[0][i] = (int *) calloc(MAX_N + 1, sizeof(int));
        adjMatrix[1][i] = (int *) calloc(MAX_N + 1, sizeof(int));
    }

    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d %d", &N, &M, &X);

        // Init
        for (int i = 1; i <= N; i++) {
            dist[0][i] = -1;
            dist[1][i] = -1;
            for (int j = 1; j <= N; j++) {
                adjMatrix[0][i][j] = 0;
                adjMatrix[1][i][j] = 0;
            }
        }

        for (int i = 0; i < M; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            adjMatrix[0][b][a] = c;
            adjMatrix[1][a][b] = c;
        }

        dijkstra(adjMatrix[0], dist[0], X, N);
        dijkstra(adjMatrix[1], dist[1], X, N);

        long result = -1;
        for (int i = 1; i <= N; i++) {
            if (i == X) {
                continue;
            }

            dist[2][i] = dist[0][i] + dist[1][i];

            if (dist[2][i] > result) {
                result = dist[2][i];
            }
        }

        printf("#%d %ld\n", test_case, result);
    }

    delete dist[0];
    delete dist[1];
    delete dist[2];
    delete dist;

    for (int i = 0; i <= MAX_N; i++) {
        delete adjMatrix[0][i];
        delete adjMatrix[1][i];
    }
    delete adjMatrix[0];
    delete adjMatrix[1];
    delete adjMatrix;

    return 0;
}

typedef struct {
    bool operator()(pair<long, int> &left, pair<long, int> &right) {
        return left.first == right.first ? left.second < right.second : left.first > right.first;
    }
} comp;

void dijkstra(int** adjMatrix, long* dist, int startIndex, int size) {
    priority_queue<pair<long, int>, vector<pair<long, int>>, comp> queue;

    queue.push({0, startIndex});
    dist[startIndex] = 0;
    while (!queue.empty()) {
        long currentDistance = queue.top().first;
        int currentIndex = queue.top().second;
        queue.pop();

        for (int nextIndex = 1; nextIndex <= size; nextIndex++) {
            if (adjMatrix[currentIndex][nextIndex] > 0) {
                long nextDistance = currentDistance + adjMatrix[currentIndex][nextIndex];
                if (dist[nextIndex] == -1 || dist[nextIndex] > nextDistance) {
                    dist[nextIndex] = nextDistance;
                    queue.push({nextDistance, nextIndex});
                }
            }
        }
    }
}

