//
// Created by shyoung.kim on 2021-05-11.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX_DAY 1000000
#define MODULAR_N 1000

int T, a, b, d, N;

class Ameba {
public:
    int date;
    int count;

    Ameba(int date, int count) {
        this->date = date;
        this->count = count;
    }

    bool operator<(const Ameba& other) {
        return this->date < other.date;
    }

    inline int age(int day) {
        return day - date;
    }

    bool isYoung(int day) {
        return age(day) < a;
    }

    bool isParent(int day) {
        return age(day) >= a && age(day) < b;
    }

    bool isDead(int day) {
        return age(day) >= d;
    }
};

int totalNumber[MAX_DAY + 1];

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d %d %d\n", &a, &b, &d, &N);

        memset(totalNumber, 0x00, sizeof(totalNumber));

        totalNumber[0] = 1;
        for (int day = 1; day <= N; day++) {
            if (day < a) {
                totalNumber[day] = totalNumber[day - 1] % MODULAR_N;
            }
            else if (day < b) {
                totalNumber[day] = (totalNumber[day - 1] + totalNumber[day - a]) % MODULAR_N;
            }
            else {
                totalNumber[day] = (totalNumber[day - 1] + totalNumber[day - a] + (MODULAR_N - totalNumber[day - b])) % MODULAR_N;
            }
        }

        int result = (totalNumber[N] - totalNumber[N - d] + MODULAR_N) % MODULAR_N;

        printf("#%d %d\n", test_case, result);
    }

    return 0;
}