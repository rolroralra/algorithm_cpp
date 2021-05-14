#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

using namespace std;

#define DEBUG
#undef DEBUG
#define TEST
#define SCALE 5

int T;
int arr[SCALE][SCALE];

const int ARRAY[SCALE][SCALE][SCALE] = {
        {
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
        },
        {
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0},
                {1, 1, 1, 1, 1},
        },
        {
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1},
        },
        {
                {1, 0, 1, 0, 0},
                {1, 0, 1, 0, 0},
                {1, 1, 1, 1, 1},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
        },
        {
                {1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0},
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1},
        },
};

int** copy(const int arr[SCALE][SCALE]);
void rotate(int arr[SCALE][SCALE], int type);
void print(int arr[SCALE][SCALE]);
int check(int arr[SCALE][SCALE]);

int main(int argc, char **argv)
{
#ifdef TEST
    std::ifstream inputStream;
    inputStream.open("../src/sample_input.txt", std::ios_base::in);
    if (inputStream.is_open()) {
        std::cin.rdbuf(inputStream.rdbuf());
#ifdef DEBUG
        cout << "file open" << endl;
#endif
    }
#endif

    std::cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int result = 0;
        for (int i = 0; i < SCALE; i++) {
            for (int j = 0; j < SCALE; j++) {
                cin >> arr[i][j];
            }
        }

        for (int rotate_type = 0; rotate_type < 4; rotate_type++) {
            rotate(arr, rotate_type);

            result = check(arr);
            if (result != 0) {
                break;
            }
        }

        cout << "#" << test_case << " " << result << endl;
    }

    return 0;
}

int** copy(const int arr[SCALE][SCALE]) {
    int** result;
    result = (int**) calloc(SCALE, sizeof(int*));
    for (int i = 0; i < SCALE; i++) {
        result[i] = (int*) calloc(SCALE, sizeof(int));
        for (int j = 0; j < SCALE; j++) {
            result[i][j] = arr[i][j];
        }
    }

    return result;
}

void rotate(int arr[SCALE][SCALE], int type) {
    if (type == 0) {
        return;
    }

    int **temp = copy(arr);

    for (int i = 0; i < SCALE; i++) {
        for (int j = 0 ; j< SCALE; j++) {
            switch(type) {
                case 1:
                    arr[i][j] = temp[SCALE - 1 - j][i];
                    break;
                case 2:
                    arr[i][j] = temp[SCALE - 1 - i][SCALE - 1 - j];
                    break;
                case 3:
                    arr[i][j] = temp[j][SCALE - 1 -i];
                    break;
            }
        }
    }

    for (int i = 0; i < SCALE; i++) {
        free(temp[i]);
    }
    free(temp);
}

void print(int arr[SCALE][SCALE]) {
    for (int i = 0; i < SCALE; i++) {
        for (int j = 0; j < SCALE; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int check(int arr[SCALE][SCALE]) {
    for (int type = 0; type < SCALE; type++) {
        bool isEqual = true;
        for (int i = 0; isEqual && i < SCALE; i++) {
            for (int j = 0; j < SCALE; j++) {
                if (arr[i][j] != ARRAY[type][i][j]) {
                    isEqual = false;
                    break;
                }
            }
        }

        if (isEqual) {
            return type + 1;
        }
    }

    return 0;
}