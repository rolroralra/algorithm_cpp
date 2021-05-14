#include <iostream>
#include <fstream>

int T;
int N, M;

struct record {
    int min;
    int sec;
    int milli_sec;
    int accumulationValue;
    int value;
    static const int MILLI_SEC_PER_SEC = 1000;
    static const int SEC_PER_MIN = 60;
};

#define TEST
#define MAX_N 100
record record_arr[MAX_N];

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

        int maxValue = -1;
        int prevMaxValue = -1;
        int minIndex = std::string::npos;
        int nextCheckIndex = std::string::npos;
        for (int i = 0; i < N; i++) {
            std::cin >> record_arr[i].min >> record_arr[i].sec >> record_arr[i].milli_sec;
            record_arr[i].accumulationValue = record_arr[i].min * record::SEC_PER_MIN * record::MILLI_SEC_PER_SEC + record_arr[i].sec * record::MILLI_SEC_PER_SEC + record_arr[i].milli_sec;
            record_arr[i].value = record_arr[i].accumulationValue;

            if (maxValue == -1 || record_arr[i].accumulationValue > maxValue) {
                maxValue = record_arr[i].accumulationValue;
            }

            if ((i + 1) % M == 0) {
                for (int j = 0; j < M; j++) {
                    int currIndex = i - j;
                    if (prevMaxValue != -1) {
                        record_arr[currIndex].value = record_arr[currIndex].accumulationValue - prevMaxValue;
                        record_arr[currIndex].min = record_arr[currIndex].value / (record::SEC_PER_MIN * record::MILLI_SEC_PER_SEC);
                        record_arr[currIndex].sec = (record_arr[currIndex].value % (record::SEC_PER_MIN * record::MILLI_SEC_PER_SEC)) / record::MILLI_SEC_PER_SEC;
                        record_arr[currIndex].milli_sec = (record_arr[currIndex].value % (record::SEC_PER_MIN * record::MILLI_SEC_PER_SEC)) % record::MILLI_SEC_PER_SEC;
                    }

                    if (minIndex == std::string::npos || record_arr[currIndex].value < record_arr[minIndex].value) {
                        minIndex = currIndex;
                    }
                }

                prevMaxValue = maxValue;
                maxValue = -1;
                nextCheckIndex = i + 1;
            }
        }

        if (nextCheckIndex < N) {
            for (int i = nextCheckIndex; i < N; i++) {
                if (prevMaxValue != -1) {
                    record_arr[i].value = record_arr[i].accumulationValue - prevMaxValue;
                    record_arr[i].min = record_arr[i].value / (record::SEC_PER_MIN * record::MILLI_SEC_PER_SEC);
                    record_arr[i].sec = (record_arr[i].value % (record::SEC_PER_MIN * record::MILLI_SEC_PER_SEC)) / record::MILLI_SEC_PER_SEC;
                    record_arr[i].milli_sec = (record_arr[i].value % (record::SEC_PER_MIN * record::MILLI_SEC_PER_SEC)) % record::MILLI_SEC_PER_SEC;
                }

                if (minIndex == std::string::npos || record_arr[i].value < record_arr[minIndex].value) {
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1) {
            for (int i = 0; i < N; i++) {
                if (minIndex == std::string::npos || record_arr[i].value < record_arr[minIndex].value) {
                    minIndex = i;
                }
            }
        }

        if (record_arr[minIndex].min != 0) {
            record_arr[minIndex].sec += record_arr[minIndex].min * record::SEC_PER_MIN;
        }

        std::cout << "#" << test_case << " " << record_arr[minIndex].sec << " " << record_arr[minIndex].milli_sec << std::endl;
    }

    return 0;
}