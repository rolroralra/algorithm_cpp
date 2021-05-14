#include <stdlib.h>
#include <iostream>

#include <string>

#define INPUT_UTIL

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define SPACE_STR " "
#define STAR_STR "*"
#define SPACE_CHAR ' '
#define STAR_CHAR '*'


//#define TEST
#define MAX_N 100000

int T;
int N, M;
int arr[MAX_N] = { 0, };
int score[MAX_N] = { 0, };
int main(int argc, char** argv) {

    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        /**************************************
        * Implementation for Algorithm Problem
        ***************************************/
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        if (N < M) {
            std::cout << "#" << test_case << " -1 -1" << std::endl;
            continue;
        }

        int count = N / M;
        int sum = 0;
        int index = 0;
        int max_score = 0;
        for (int i = 0; i < M; i++) {
            score[i] = 0;
        }
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < M; j++) {
                int card = arr[i * M + j];
                score[j] += card;
                sum += card;
                if (max_score < score[j]) {
                    max_score = score[j];
                }
            }
        }

        std::cout << "#" << test_case << SPACE_STR << sum << SPACE_STR << max_score << std::endl;

    }

#ifdef TEST
    inputFileStream.close();
#endif

    return 0;
}
