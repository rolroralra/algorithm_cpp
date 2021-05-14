#include <fstream>
#include <iostream>

using namespace std;


#define FRUIT_COUNT 3
#define MAX_N 100
#define MIN_GAP 500

int T, N;
int arr[MAX_N + 1][FRUIT_COUNT];

bool check(int index);

int main(int argc, char **argv)
{
    ifstream inputStream;
    inputStream.open("../src/sample_input.txt");
    if (inputStream.is_open()) {
        cin.rdbuf(inputStream.rdbuf());
    }

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int result = 0;
        cin >> N >> arr[0][0] >> arr[0][1] >> arr[0][2];
        for (int i = 1; i <= N; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
            if (check(i)) {
                result++;
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }


    return 0;
}

bool check(int index) {
    int fullySatisfiedCount = 0;
    int partialSatisfiedCount = 0;
    for (int fruitIndex = 0; fruitIndex < FRUIT_COUNT; fruitIndex++) {
        if (arr[index][fruitIndex] <= arr[0][fruitIndex]) {
            fullySatisfiedCount++;
        }
        else if (arr[index][fruitIndex] - arr[0][fruitIndex] <= MIN_GAP) {
            partialSatisfiedCount++;
        }
    }

    return fullySatisfiedCount == 3 || (fullySatisfiedCount == 2 && partialSatisfiedCount == 1);
}


//#1 1
//#2 4
//#3 1
//#4 3
//#5 7
