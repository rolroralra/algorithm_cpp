#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


#define MAX_N 100

int T, N;

typedef class Candidate {
private:
public:
    int id;
    int count;
    int lastIndex;
    bool isSelected;

    Candidate() {
        init(-1);
    }

    void init(int id) {
        this->id = id;
        this->count = 0;
        this->lastIndex = -1;
        this->isSelected = false;
    }

    bool operator < (const Candidate &right) const {
        return this->count > right.count || this->lastIndex > right.lastIndex;
    }

    bool operator > (const Candidate &right) const {
        return this->count < right.count || this->lastIndex < right.lastIndex;
    }

    std::string toString() {
        char buff[1000];
        snprintf(buff, sizeof(buff), "id: %d, count:%d, lastIndex:%d, isSelected:%s", this->id, this->count, this->lastIndex, this->isSelected ? "true" : "false");
        return buff;
    }
} Candidate;

Candidate candidateArray[MAX_N + 1];

int main(int argc, char **argv)
{
    ifstream inputStream;
    inputStream.open("../src/sample_input.txt", ios_base::in);
    if (inputStream.is_open()) {
        cin.rdbuf(inputStream.rdbuf());
    }

    cin >> T;

    int totalCount;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        cin >> totalCount;

        for (int i = 1; i <= MAX_N; i++) {
            candidateArray[i].init(i);
        }

        vector<Candidate*> list;
        int candidateId;
        for (int i = 0; i < totalCount; i++) {
            cin >> candidateId;
//            cout << "candidateId: " << candidateId << endl;
            if (candidateArray[candidateId].isSelected) {
                candidateArray[candidateId].count++;
                continue;
            }

//            cout << "size: " << list.size() << endl;

            if (list.size() >= N) {
                sort(list.begin(), list.end(), [](const Candidate* left, const Candidate* right)->bool{
                    return left->count == right->count ? left->lastIndex > right->lastIndex : left->count > right->count;
                });

//                for_each(list.begin(), list.end(), [](Candidate* v)->void{cout << v->toString() << endl;});

                int id = list[N - 1]->id;
//                cout << "removeId: " << id << endl;
                candidateArray[id].init(id);
                list.erase(list.begin() + N - 1);

//                cout << candidateArray[id].toString() << endl;
            }

            candidateArray[candidateId].lastIndex = i;
            candidateArray[candidateId].isSelected = true;
            candidateArray[candidateId].count = 1;
            list.push_back(&candidateArray[candidateId]);
        }

        cout << "#" << test_case;
        for (int i = 1; i <= MAX_N; i++) {
            if (candidateArray[i].isSelected) {
                cout << " " << i;
            }
        }
        cout << endl;

    }

    return 0;
}


