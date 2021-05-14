#include <fstream>
#include <iostream>

using namespace std;


#define MAX_N 100
#define MAX_L 20

int T, N, L;
int price[MAX_N][MAX_L];
int minPrice[MAX_L];

int main(int argc, char **argv)
{
    ifstream inputStream;
    inputStream.open("../src/sample_input.txt");
    if (inputStream.is_open()) {
        cin.rdbuf(inputStream.rdbuf());
    }

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N >> L;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < L; j++) {
                cin >> price[i][j];

                if (i == 0) {
                    minPrice[j] = price[i][j];
                }
                else {
                    minPrice[j] = price[i][j] < minPrice[j] ? price[i][j] : minPrice[j];
                }
            }
        }

        int result = 0;
        for (int i = 0; i < L; i++) {
            result += minPrice[i];
        }

        cout << "#" << test_case << " " << result << endl;
    }


    return 0;
}


//#1 37
//#2 152
//#3 117
//#4 144
//#5 170
//#6 292
//#7 265
//#8 363
//#9 196
//#10 203