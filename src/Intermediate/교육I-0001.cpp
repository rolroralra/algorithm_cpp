#include<cstdio>
using namespace std;

int N;

int main() {
    //setbuf(stdout, nullptr);
    //freopen("sample_input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);
    for (int test_case = 1; test_case <= TC; test_case++) {
        scanf("%d", &N);

        int count = 1;
        while (1 < N) {
            N = (float)N / 2;
            count++;
        }

        printf("#%d %d\n", test_case, count);
    }

    return 0;
}
