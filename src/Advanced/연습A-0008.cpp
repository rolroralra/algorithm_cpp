//
// Created by shyoung.kim on 2021-02-17.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define MAX_N 1000

int T, N, M;

class Player {
private:
public:
    int id;
    bool isConnected[MAX_N + 1] {false, };
    int connectCount;
    vector<int> list;

    Player() : id(-1), connectCount(0) {
        init(-1);
    }

    void init(int _id) {
        this->id = _id;
        for (int i = 0; i < this->connectCount; i++) {
            this->isConnected[list[i]] = false;
        }
        list.clear();
        this->connectCount = 0;
    }

    void connect(int targetIndex) {
        if (!this->isConnected[targetIndex]) {
            this->connectCount++;
            this->isConnected[targetIndex] = true;
            this->list.push_back(targetIndex);
        }
    }

    std::string toString() {
        stringstream ss;
        ss << "id: " << id;
        ss << ", connectCount: " << connectCount;
        ss << ", isConnected:";
        for_each(isConnected, isConnected + N + 1, [&ss](bool v)->void{ss << " " << v;});
        ss << ", list:";
        for_each(list.begin(), list.end(), [&ss](int v)->void{ss << " " << v;});

        return ss.str();
    }
};

Player aPlayers[MAX_N + 1];

int main(int argc, char **argv)
{
    ifstream inputStream;
    inputStream.open("../src/sample_input.txt", ios_base::in);
    if (inputStream.is_open()) {
        cin.rdbuf(inputStream.rdbuf());
    }

    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            aPlayers[i].init(i);
        }

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            aPlayers[a].connect(b);
        }

        long result = 0;
        for (int a1 = 1; a1 < N; a1++) {
            for (int a2 = a1 + 1; a2 <= N; a2++) {
                if (aPlayers[a1].connectCount < 2 || aPlayers[a2].connectCount < 2) {
                    continue;
                }

                int commonCount = 0;

                for_each(aPlayers[a1].list.begin(), aPlayers[a1].list.end(), [a2, &commonCount](int target)->void{
                    if (aPlayers[a2].isConnected[target]) {
                        commonCount++;
                    }
                });

                if (commonCount >= 2) {
                    result += (commonCount * (commonCount - 1)) / 2;
                }
            }
        }

        cout << "#" << test_case << " " << result << endl;

    }

    return 0;
}


