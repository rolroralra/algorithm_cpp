
#include <bits/stdc++.h>

#define MAX_N 1000
int T, N, K;

unsigned char sieve[(MAX_N + sizeof(char) - 1) / sizeof(char)];
bool isPrime(int index);
bool isComposite(int index);
void setPrime(int index);
void setComposite(int index);

int main() {
    freopen("../src/sample_input.txt", "r", stdin);

    scanf("%d\n", &N);
    memset(sieve, (1 << (sizeof(char) << 3)) - 1, sizeof(sieve));

    setComposite(0);
    setComposite(1);
    for (int i = 2; i * i <= MAX_N; i++) {
        if (isComposite(i)) {
            continue;
        }

        for (int j = i * i; j <= MAX_N; j += i) {
            setComposite(j);
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d ", &input);

        if (isPrime(input)) {
            result++;
        }
    }

    printf("%d\n", result);

    return 0;
}

bool isPrime(int index) {
    return sieve[index / 8] & (1 << (index % 8));
//    return arr[index >> 3] & (1 << (index & 7));
}

bool isComposite(int index) {
    return !isPrime(index);
//    return arr[index / 8]
}

void setPrime(int index) {
    sieve[index / 8] |=  1 << (index % 8);
}

void setComposite(int index) {
    sieve[index / 8] &= ~(1 << (index % 8));
}
