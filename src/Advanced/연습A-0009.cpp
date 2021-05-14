//
// Created by shyoung.kim on 2021-02-18.
//
#include <iostream>

using namespace std;

#define MAX_N 250
int T, N;

int arr[MAX_N][MAX_N];

int main(int argc, char** argv) {
    FILE *fp;
//    fp = fopen("../src/sample_input.txt", "r");
    fp = stdin;

    fscanf(fp, "%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        fscanf(fp, "%d", &N);

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fscanf(fp, "%d", &arr[i][j]);

                if (i > 0 && j > 0 && arr[i][j] == 1) {
                    arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;

                    if (arr[i][j] > 1) {
                        result += arr[i][j] - 1;
                    }
                }

//                printf("%d ", arr[i][j]);
            }
//            printf("\n");
        }

        printf("#%d %d\n", test_case, result);
    }

    fclose(fp);

    return 0;
}