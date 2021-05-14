#include <iostream>
#include <fstream>

int T;
int N, M;

#define TEST
#define MAX_N 1000000
#define MAX_M 100000

int isAnswer[MAX_N];
int cacheEndIndex[MAX_N];

int main(int argc, char **argv)
{
#ifdef TEST
    std::ifstream inputStream;
    inputStream.open("../src/sample_input.txt", std::ios_base::in);
    if (inputStream.is_open()) {
        std::cin.rdbuf(inputStream.rdbuf());
    }
#endif

    std::cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        std::cin >> N >> M;

        std::fill(isAnswer, isAnswer + N, -1);
        std::fill(cacheEndIndex, cacheEndIndex + N, -1);

        int endIndex = N;
        int startIndex = 1;
        int prevEnd = -1;
        for (int i = 0; i < M; i++) {
            int start, end, isExist;
            std::cin >> start >> end >> isExist;
            if (isExist == 1) {
                if (endIndex > end) {
                    endIndex = end;
                }

                if (startIndex < start) {
                    startIndex = start;
                }
            } else {

                if (end <= prevEnd) {
                    continue;
                }

                if (start <= prevEnd) {
                    start = prevEnd + 1;
                }

                for (int j = start - 1; j < end; j++) {
                    isAnswer[j] = 0;
                }

                prevEnd = end;
            }
        }


        int answer = -1;
        for (int i = startIndex - 1; i < endIndex; i++) {
            if (isAnswer[i] != 0) {
                answer = i + 1;
                break;
            }
        }

        std::cout << "#" << test_case << " " << answer << std::endl;
    }

    return 0;
}

//#1 5
//#2 7
//#3 25
//#4 96
//#5 73
//#6 143
//#7 311
//#8 541
//#9 463
//#10 719