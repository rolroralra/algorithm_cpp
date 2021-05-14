//
// Created by shyoung.kim on 2021-03-19.
//

#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

#define MAX_N 3000
#define MAX_M 20000

int T, N, M, B;
int adjMatrix[MAX_N + 1][MAX_N + 1];
long long dist[2][MAX_N + 1];
class DistanceInfo {
public:
    int index;
    long long distance;

    DistanceInfo(int index, long long distance) {
        this->index = index;
        this->distance = distance;
    }

    const bool operator< (const DistanceInfo &other) const {
        return this->distance == other.distance ? this->index > other.index : this->distance > other.distance;
    }
};

int main(int argc, char** argv) {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d", &N, &M);
        scanf("%d", &B);

        for (int i = 1; i <= N; i++) {
            dist[0][i] = -1;
            dist[1][i] = -1;
        }
        memset(adjMatrix, 0x00, sizeof(adjMatrix));
        for (int i = 0; i < M; i++) {
            int src, dest, length;
            scanf("%d %d %d", &src, &dest, &length);

            if (adjMatrix[src][dest] == 0 || adjMatrix[src][dest] > length) {
                adjMatrix[src][dest] = length;
            }
        }

        priority_queue<DistanceInfo> queue[2];

        dist[0][1] = 0L;
        queue[0].emplace(1, dist[0][1]);
        dist[1][B] = 0L;
        queue[1].emplace(B, dist[1][B]);
        for (int i = 0; i < 2; i++) {
            while (!queue[i].empty()) {
                DistanceInfo distanceInfo = queue[i].top();
                queue[i].pop();

                int currentIndex = distanceInfo.index;
                long long currentDistance = distanceInfo.distance;

                if (dist[i][currentIndex] < currentDistance) {
                    continue;
                }

                for (int nextIndex = 1; nextIndex <= N; nextIndex++) {
                    if (adjMatrix[currentIndex][nextIndex] == 0) {
                        continue;
                    }

                    long long nextDistance = currentDistance + (long long) adjMatrix[currentIndex][nextIndex];
                    if (dist[i][nextIndex] == -1 || dist[i][nextIndex] > nextDistance) {
                        dist[i][nextIndex] = nextDistance;
                        queue[i].emplace(nextIndex, nextDistance);
                    }
                }
            }
        }

        if (dist[0][B] == -1 || dist[1][1] == -1) {
            printf("#%d NO\n", test_case);
        }
        else {
            printf("#%d YES %ld\n", test_case, dist[0][B] + dist[1][1]);
        }
    }

    return 0;
}



