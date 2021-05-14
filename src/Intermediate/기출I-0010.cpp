#include <iostream>
#include <fstream>

using namespace std;

// Number: 123
// Color: RGP
// Shape: EDT
// Shadow: FSW
typedef class Card {
public:
    int number;
    char color;
    char shape;
    char shadow;

    Card() {
        init(1, 'R', 'E', 'F');
    }
    Card(int number, char color, char shape, char shadow) {
        init(number, color, shape, shadow);
    }

    Card (std::string str) {
        init(str);
    }

    void init (std::string str) {
        const char* tmp = str.c_str();
        init(tmp[0] - '0', tmp[1], tmp[2], tmp[3]);
    }

    void init(int number, char color, char shape, char shadow) {
        this->number = number;
        this->color = color;
        this->shape = shape;
        this->shadow = shadow;
    }

    void print() {
        cout << number << color << shape << shadow << endl;
    }

    bool isValid(Card obj, bool isEqual[4]) {
        return ((obj.number == this->number) == isEqual[0])
               && ((obj.color == this->color) == isEqual[1])
               && ((obj.shape == this->shape) == isEqual[2])
               && ((obj.shadow == this->shadow) == isEqual[3]);
    }
} Card;

#define MAX_N 81
int T, N;
Card arr[MAX_N];
Card list[3];
bool isEqual[4];

int combination(int startIndex, int count);

int main(int argc, char **argv)
{
    ifstream inputStream;
    inputStream.open("../src/sample_input.txt");
    if (inputStream.is_open()) {
        cin.rdbuf(inputStream.rdbuf());
        cout << "file open" << endl;
    }

    cin >> T;

    std::string input;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        for (int i = 0 ; i < N; i++) {
            cin >> input;
            arr[i].init(input);
        }

        int result = combination(0, 0);
        cout << "#" << test_case << " " << result << endl;
    }


    return 0;
}

int combination(int startIndex, int count) {
    if (count == 3) {
        if (list[0].isValid(list[1], isEqual) && list[0].isValid(list[2], isEqual) && list[1].isValid(list[2], isEqual)) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int result = 0;

    for (int nextIndex = startIndex; nextIndex < N; nextIndex++) {
        if (count == 2) {
            isEqual[0] = list[0].number == list[1].number;
            isEqual[1] = list[0].color == list[1].color;
            isEqual[2] = list[0].shape == list[1].shape;
            isEqual[3] = list[0].shadow == list[1].shadow;
        }

        list[count] = arr[nextIndex];
        result += combination(nextIndex + 1, count + 1);
    }

    return result;
}

//#1 1
//#2 2
//#3 2
//#4 10
//#5 29
//#6 35
//#7 74
//#8 105
//#9 214
//#10 262