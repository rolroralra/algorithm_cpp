//
// Created by shyoung.kim on 2021-02-18.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define TEST

#define MAX_N 100000
int T, N, M;

vector<pair<int, int>> adjList[MAX_N];
long dist[MAX_N + 1];

void init(int size);

int main(int argc, char** argv) {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d", &N, &M);

        init(N);

        for (int i = 0 ; i < M; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            if (a < b) {
                adjList[a].emplace_back(b, c);
            }
        }

        typedef struct {
            bool operator()(pair<int, long> &left, pair<int, long> &right) {
                return left.second == right.second ? left.first < right.first : left.second > right.second;
            }
        } comp;

        priority_queue<pair<int, long>, vector<pair<int, long>>, comp> priorityQueue;

        dist[1] = 0;
        priorityQueue.emplace(1, 0);
        while (!priorityQueue.empty()) {
            int currIndex = priorityQueue.top().first;
            long currDistance = priorityQueue.top().second;
            priorityQueue.pop();

            if (currIndex == N) {
                break;
            }

            if (dist[currIndex] < currDistance) {
                continue;
            }

            for (auto next : adjList[currIndex]) {
                int nextIndex = next.first;
                long nextDistance = dist[currIndex] + (long) next.second;

                if (dist[nextIndex] == -1 || dist[nextIndex] > nextDistance) {
                    dist[nextIndex] = nextDistance;
                    priorityQueue.emplace(nextIndex, nextDistance);
                }
            }
        }

        printf("#%d %ld\n", test_case, dist[N]);
    }


    return 0;
}

void init(int size) {
    for (int i = 1; i <= size; i++) {
        adjList[i].clear();
        dist[i] = -1;
    }
}
