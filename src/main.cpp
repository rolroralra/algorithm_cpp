    #include <bits/stdc++.h>

    using namespace std;

    int A, N, B;
    string str;
    void printConvertNumber(string numberString, int fromBase, int toBase);

    int main() {
        freopen("../src/sample_input.txt", "r", stdin);
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        while (true) {
            scanf("%d", &A);
            if (A == 0) {
                break;
            }

            cin >> str;

            scanf("%d\n", &B);
    //        printf("%d %s %d\n", A, str.c_str(), B);
            printConvertNumber(str, A, B);
        }

        return 0;
    }

    void printConvertNumber(string numberString, int fromBase, int toBase) {
        long long number = 0;
        for (const auto &c : numberString) {
            number *= fromBase;
            if (isdigit(c)) {
                number += (long long) (c - '0');
            }
            else if (isupper(c)) {
                number += (long long) (c - 'A') + 10;
            }
            else {
                return;
            }
        }

        stack<char> stk;

        do {
            int remainder = (int) (number % toBase);

            if (remainder < 10) {
                stk.push((char) ('0' + remainder));
            }
            else {
                stk.push((char) ('A' + remainder - 10));
            }

            number /= toBase;
        } while (number > 0);

        while (!stk.empty()) {
            printf("%c", stk.top());
            stk.pop();
        }
        printf("\n");
    }