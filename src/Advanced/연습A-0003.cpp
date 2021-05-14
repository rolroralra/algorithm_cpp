#include <iostream>
#include <fstream>

using namespace std;

int T, N;
int hanoiTower(int n, int src, int gateway, int dest, std::string *columnNames, std::string &result);

int main(int argc, char **argv)
{
    ifstream inputStream;
    inputStream.open("../src/sample_input.txt");
    if (inputStream.is_open()) {
        cin.rdbuf(inputStream.rdbuf());
    }

    std::string columnNames[3] = {"A", "B", "C"};
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        std::string output;
        int result = hanoiTower(N, 0, 1, 2, columnNames, output);

        cout << "#" << test_case << " " << result << endl;
        cout << output;
    }

    return 0;
}

int hanoiTower(int n, int src, int gateway, int dest, std::string *columnNames, std::string &result) {
    char buff[1000];
    if (n == 1) {
        snprintf(buff, sizeof(buff), "%d : %s -> %s\n", n, columnNames[src].c_str(), columnNames[dest].c_str());
        result.append(buff);
        return 1;
    }

    int countResult = 0;

    countResult += hanoiTower(n - 1, src, dest, gateway, columnNames, result);
    snprintf(buff, sizeof(buff), "%d : %s -> %s\n", n, columnNames[src].c_str(), columnNames[dest].c_str());
    result.append(buff);
    countResult++;

    countResult += hanoiTower(n - 1, gateway, src, dest, columnNames, result);

    return countResult;
}

