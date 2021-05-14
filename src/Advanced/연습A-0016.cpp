//
// Created by shyoung.kim on 2021-05-11.
//

#include <bits/stdc++.h>

using namespace std;

int T, N, K;

class Diamond {
public:
    int mass;
    int value;

    Diamond(int mass, int value) {
        this->mass = mass;
        this->value = value;
    }

    bool operator<(const Diamond& other) const {
        return this->value == other.value ? this->mass > other.mass : this->value < other.value;
    }
};

class Bag {
public:
    int mass;

    Bag(int mass) {
        this->mass = mass;
    }

    bool operator<(const Bag& other) const {
        return this->mass < other.mass;
    }
};

//struct CustomCompare {
//    bool operator()(const Diamond &l, const Diamond &r) {
//        return l.second == r.second ? l.first > r.first : l.second > r. second;
//    }
//};

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d\n", &N, &K);

        vector<Diamond> diamondList;
        vector<Bag> bagList;
        priority_queue<Diamond, vector<Diamond>> priorityQueue;

        for (int i = 0; i < N; i++) {
            int mass, value;
            scanf("%d %d\n", &mass, &value);
            diamondList.emplace_back(mass, value);
        }

        for (int i = 0; i < K; i++) {
            int mass;
            scanf("%d\n", &mass);
            bagList.emplace_back(mass);
        }

        sort(bagList.begin(), bagList.end());
        sort(diamondList.begin(), diamondList.end(), [](const Diamond &l, const Diamond &r)->bool{return l.mass < r.mass;});

        long long result = 0;
        int index = 0;
        for (auto bag : bagList) {
            while (index < N) {
                if (diamondList[index].mass > bag.mass) {
                    break;
                }

                priorityQueue.push(diamondList[index++]);
            }

            if (priorityQueue.empty()) {
                continue;
            }

            result += (long long) priorityQueue.top().value;
            priorityQueue.pop();
        }

        printf("#%d %ld\n", test_case, result);
    }

    return 0;
}