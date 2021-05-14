//
// Created by shyoung.kim on 2021-03-29.
//

#include <bits/stdc++.h>

using namespace std;

// Karatsuba Algorithm
class Number {
public:
    vector<int> numberList;

    explicit Number(const string &s) {
        this->numberList = Number::getNumberList(s);
    }

    explicit Number(const vector<int> &list) {
        this->numberList = list;

        int result = 0;
        for_each(list.begin(), list.end(), [&result](int v)->void{result = result * 10 + v;});
    }

    explicit Number(const int n) {
        Number number = Number(to_string(n));
        init(number.numberList);
    }

    static vector<int> getNumberList(const char* arr) {

    }

    static vector<int> getNumberList(const string &s) {
        vector<int> result(s.length());

        unsigned long long i = s.length() - 1;
        for_each(s.begin(), s.end(), [&result, &i](char c)->void{result[i--] = c - '0';});

        return result;
    }
    static void normalize(vector<int> &numberList) {
        numberList.push_back(0);

        unsigned long long size = numberList.size() - 1;
        for (int i = 0; i < size; i++) {
            if (numberList[i] < 0) {
                int borrow = (abs(numberList[i]) + 9) / 10;
                numberList[i + 1] -= borrow;
                numberList[i] += borrow * 10;
            } else {
                numberList[i + 1] += numberList[i] / 10;
                numberList[i] %= 10;
            }
        }

        while (numberList.size() > 1 && numberList.back() == 0) {
            numberList.pop_back();
        }
    }

    static Number add(const Number &a, const Number &b) {
        int aSize = a.numberList.size();
        int bSize = b.numberList.size();
        int size = max(aSize, bSize);

        vector<int> c(size, 0);

        for (int i = 0; i < size; i++) {
            if (i < aSize) {
                c[i] += a.numberList[i];
            }

            if (i < bSize) {
                c[i] += b.numberList[i];
            }
        }


        normalize(c);
        return Number(c);
    }

    static Number subtract(const Number &a, const Number &b) {
        int aSize = a.numberList.size();
        int bSize = b.numberList.size();

        vector<int> c(aSize, 0);

        c.assign(a.numberList.begin(), a.numberList.end());

        for (int i = 0; i < bSize; i++) {
            c[i] -= b.numberList[i];
        }

        normalize(c);
        return Number(c);
    }

    static Number multiply(const Number &a, const Number &b) {
        int aSize = a.numberList.size();
        int bSize = b.numberList.size();

        vector<int> c(aSize + bSize + 1, 0);

        for (int i = 0; i < aSize; i++) {
            for (int j = 0; j < bSize; j++) {
                c[i + j] += a.numberList[i] * b.numberList[j];
            }
        }

        normalize(c);
        return Number(c);
    }

    Number operator+(const Number &ref) const {
        return Number::add(*this, ref);
    }

    Number operator*(const Number &ref) const {
        return Number::multiply(*this, ref);
    }

    Number operator-(const Number &ref) const {
        return Number::subtract(*this, ref);
    }

    Number operator<<(const int b) {
        vector<int> c(this->numberList.size() - b);

        int size = this->numberList.size();
        for (int i = b; i < size; i++) {
            c[i - b] = this->numberList[i];
        }

        normalize(c);
        return Number(c);
    }

    Number operator>>(const int b) {
        vector<int> c(this->numberList.size() + b);

        int size = this->numberList.size();
        for (int i = 0; i < size; i++) {
            c[i + b] = this->numberList[i];
        }

        normalize(c);
        return Number(c);
    }


    string toString() const {
        stringstream ss;

        vector<int> list = this->numberList;
//        reverse(list.begin(), list.end());
//        for_each(list.begin(), list.end(), [&ss](int v)->void{ss << v;});
        for (int i = this->numberList.size() - 1; i > -1; i--) {
            ss << this->numberList[i];
        }

        return ss.str();
    }
private:
    void init(const vector<int> &numberList) {
        this->numberList = numberList;
    }
};