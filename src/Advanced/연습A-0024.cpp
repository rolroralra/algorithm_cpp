//
// Created by shyoung.kim on 2021-04-01.
//

#include <bits/stdc++.h>

using namespace std;

int T;
long long a, m;
long long int MOD = 1000000007;
long long cache[64];

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%ld %ld", &a, &m);

        cache[0] = a % MOD;
        for (int i = 1; i < 64; i++) {
            cache[i] = cache[i - 1] * cache[i - 1] % MOD;
        }

        long long result = 1;
        for (int i = 0; i < 63; i++) {
            if ((m >> i) & 1L) {
                result = result * cache[i] % MOD;
            }
        }

        printf("#%d %ld\n", test_case, result);
    }

    return 0;
}

