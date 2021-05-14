//
// Created by shyoung.kim on 2021-04-01.
//

#include <bits/stdc++.h>

using namespace std;

int factorial(int n);

#define MAX_N 10

int T, N;
char src[MAX_N + 1];
char dst[MAX_N + 1];
int cache[11];

int factorial(int n) {
    if (cache[n] != 0) {
        return cache[n];
    }

    int result = n;
    for (int i = n - 1; i > 0; i--) {
        if (cache[i] != 0) {
            result *= cache[i];
            break;
        }

        result *= i;
    }

    return cache[n] = result;
}

int stringIndexOf(char *str) {
    int size = strlen(str);
    bool *isChecked = (bool *) calloc(size, sizeof(bool));

    int result = 0;
    for (int i = 0; i < size; i++) {
        int currentCharIndex = str[i] - 'a';
        isChecked[currentCharIndex] = true;
        int count = 0;
        for (int j = 0; j < currentCharIndex; j++) {
            if (!isChecked[j]) {
                count++;
            }
        }

        result += count * factorial(size - i - 1);
    }

    return result;
}

int main() {
    freopen("../src/sample_input.txt", "r", stdin);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %s %s",&N, src, dst);

        printf("#%d %ld\n", test_case, abs(stringIndexOf(src) - stringIndexOf(dst)) - 1);
    }

    return 0;
}

