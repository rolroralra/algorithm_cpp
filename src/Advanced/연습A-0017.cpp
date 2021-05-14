#include <bits/stdc++.h>

using namespace std;

#define MAX_N 5842
#define NUMBER_OF_PRIME 4

int T, N;

long long result;

long long cache[MAX_N];
int primeArray[NUMBER_OF_PRIME] = {2, 3, 5, 7};

long long primeMultipleNumber(int n);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d\n", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d\n", &N);
        result = primeMultipleNumber(N - 1);
        printf("#%d %ld\n", test_case, result);
    }

    return 0;
}

long long primeMultipleNumber(int n) {
    if (cache[n] != 0) {
        return cache[n];
    }

    switch (n) {
        case 0:
            return cache[n] = 1;
        case 1:
        case 2:
            return cache[n] = primeArray[n - 1];
        default:
            break;
    }

    long long result = LONG_LONG_MAX;
    for (int i = n - 1; i > -1; i--) {
        bool isChanged = false;
        for (auto prime : primeArray) {
            long long nextPrimeMultipleNumber = primeMultipleNumber(i) * prime;
            if (primeMultipleNumber(n - 1) < nextPrimeMultipleNumber) {
                result = min(result, nextPrimeMultipleNumber);
                isChanged = true;
            }
        }

        if (!isChanged) {
            break;
        }
    }

    return cache[n] = result;
}

