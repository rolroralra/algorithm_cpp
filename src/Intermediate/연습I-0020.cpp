#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <limits>
#include <functional>
#include <algorithm>
//#include "lib/header/string_lib.h"

#define TEST
//#define STRING_TRIM

using namespace std;

/*************************************************************************/
/* Libarary Function
/*************************************************************************/
std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, char delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, std::string delimiter);
std::vector<std::string> getInputList();

int parseInt(std::string str);

#ifdef STRING_TRIM
void ltrim(std::string& s);
void rtrim(std::string& s);
void trim(std::string& s);
std::string ltrim_copy(std::string s);
std::string rtrim_copy(std::string s);
std::string trim_copy(std::string s);
#endif
/*************************************************************************/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define SPACE_STR " "
#define STAR_STR "*"
#define SPACE_CHAR ' '
#define STAR_CHAR '*'


#define MAX_N 20

int T;
int N, K;
int arr[MAX_N][MAX_N] = { {0,}, };

int main(int argc, char** argv) {

#ifdef TEST
	string filePath = "sample_input.txt";

	// read File
	ifstream inputFileStream;
	inputFileStream.open(filePath, ios_base::in);
	//ifstream openFile(filePath);
	if (inputFileStream.is_open()) {
		std::cin.rdbuf(inputFileStream.rdbuf());  // swap
	}
#endif

	string input;
	vector<string> input_list;

	//std::getline(std::cin, input);
	//input_list = split(input, SPACE_STR);
	input_list = getInputList();
	T = std::atoi(input_list[0].c_str());

	for (int test_case = 1; test_case <= T; test_case++) {
		/**************************************
		* Implementation for Algorithm Problem
		***************************************/

		//std::getline(std::cin, input);
		input_list = getInputList();
		N = std::atoi(input_list[0].c_str());

		vector<pair<int, int>> col_sum;
		for (int i = 0; i < N; i++) {
			col_sum.push_back(make_pair(i, 0));
		}

		for (int i = 0; i < N; i++) {
			input_list = getInputList();

			for (int j = 0; j < N; j++) {
				arr[i][j] = std::atoi(input_list[j].c_str());
				col_sum[j].second += arr[i][j];
			}
		}

		// std::sort(iterator begin, iterator end, predicate)
		std::sort(col_sum.begin(), col_sum.end(), [](pair<int, int> a, pair<int, int> b)->bool {return a.second < b.second; });

		for (int i = 0; i < N; i++) {
			col_sum[i].second = arr[N - 1][col_sum[i].first];
		}

		std::cout << "#" << test_case;
		for (int i = 0; i < N; i++) {
			std::cout << SPACE_STR << col_sum[i].second;
		}
		std::cout << std::endl;

	}

#ifdef TEST
	inputFileStream.close();
#endif

	return 0;
}



inline int parseInt(std::string str) {
	return std::atoi(str.c_str());
}

inline std::vector<std::string> getInputList() {
	return getInputListFromInputstreamLine(std::cin, SPACE_STR);
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, std::string delimiter) {
	std::string buffer;
	std::getline(inputStream, buffer);
	return split(buffer, delimiter);
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, char delimiter) {
	std::string buffer;
	std::getline(inputStream, buffer);
	return split(buffer, delimiter);
}

inline vector<string> split(string str, char delimiter) {
	vector<string> list;
	stringstream ss(str);
	string temp;

	while (std::getline(ss, temp, delimiter)) {
		list.push_back(temp);
	}

	return list;
}

inline vector<string> split(string s, string delimiter) {
	vector<string> list;

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);

		if (token.length() != 0 && token.compare(delimiter) != 0) {
			list.push_back(token);
		}

		s.erase(0, pos + delimiter.length());
	}
	list.push_back(s);

	return list;
}



