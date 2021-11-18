#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <limits>
//#include "lib/header/string_lib.h"

#define TEST
//#define STRING_TRIM

/*************************************************************************/
// Libarary Function
/*************************************************************************/
std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, char delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, std::string delimiter);

#ifdef STRING_TRIM
void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);
std::string ltrim_copy(std::string s);
std::string rtrim_copy(std::string s);
std::string trim_copy(std::string s);
#endif
/*************************************************************************/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_N 11
#define SPACE_STR " "
#define STAR_STR "*"
#define SPACE_CHAR ' '
#define STAR_CHAR '*'

int T;
int N;
int arr[MAX_N][MAX_N];

int main(int argc, char **argv)
{
    freopen("../src/sample_input.txt", "r", stdin);
//#ifdef TEST
//    std::string filePath = "../src/sample_input.txt";
//
//    // read File
//    std::ifstream inputFileStream;
//    inputFileStream.open(filePath, std::ios_base::in);
//    if (inputFileStream.is_open())
//    {
//        std::cin.rdbuf(inputFileStream.rdbuf()); // swap
//    }
//#endif
    std::string input;
    std::vector<std::string> input_list;

    input_list = getInputListFromInputstreamLine(std::cin, SPACE_CHAR);
    T = std::atoi(input_list[0].c_str());

    for (int test_case = 1; test_case <= T; test_case++)
    {
        input_list = getInputListFromInputstreamLine(std::cin, SPACE_CHAR);
        N = std::atoi(input_list[0].c_str());

        /**************************************
        * Implementation for Algorithm Problem
        ***************************************/
        std::cout << "#" << test_case << SPACE_STR;
        std::cout << std::endl;
    }

#ifdef TEST
    inputFileStream.close();
#endif

    return 0;
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, std::string delimiter)
{
    std::string buffer;
    std::getline(inputStream, buffer);
    return split(buffer, delimiter);
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream &inputStream, char delimiter)
{
    std::string buffer;
    std::getline(inputStream, buffer);
    return split(buffer, delimiter);
}

inline std::vector<std::string> split(std::string str, char delimiter)
{
    std::vector<std::string> list;
    std::stringstream ss(str);
    std::string temp;

    while (std::getline(ss, temp, delimiter))
    {
        list.push_back(temp);
    }

    return list;
}

inline std::vector<std::string> split(std::string s, std::string delimiter)
{
    std::vector<std::string> list;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);

        if (token.length() != 0 && token.compare(delimiter) != 0)
        {
            list.push_back(token);
        }

        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);

    return list;
}
