#include <iostream>
#include <stdlib.h>
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

using namespace std;

/*************************************************************************/
/* Libarary Function
/*************************************************************************/
std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, std::string delimiter);

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

#define MAX_N 100

enum OX : char {
	O = 'O',
	X = 'X'
};

int T;
int N;
std::array<std::string, MAX_N> string_array;
int result[MAX_N][MAX_N];

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
	//input_list = split(input, " ");
	input_list = getInputListFromInputstreamLine(std::cin, " ");
	T = std::atoi(input_list[0].c_str());

	for (int test_case = 1; test_case <= T; test_case++) {
		//std::getline(std::cin, input);
		input_list = getInputListFromInputstreamLine(std::cin, " ");
		N = std::atoi(input_list[0].c_str());

		for (int i = 0; i < N; i++) {
			input_list = getInputListFromInputstreamLine(std::cin, " ");
			string_array[i] = input_list[0];
		}


		/**************************************
		* Implementation for Algorithm Problem
		***************************************/

		std::cout << "#" << test_case << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				result[i][j] = string_array[i][j] == OX::O ? 1 : 0;

				std::cout << result[i][j];

				if (j != N - 1) {
					std::cout << " ";
				}
			}
			std::cout << endl;
		}
	}

#ifdef TEST
	inputFileStream.close();
#endif

	return 0;
}

inline std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, std::string delimiter) {
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
		list.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	list.push_back(s);

	return list;
}

#ifdef STRING_TRIM
// trim from start (in place)
inline void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}

// trim from end (in place)
inline void rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string& s) {
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
inline std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)
inline std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)
inline std::string trim_copy(std::string s) {
	trim(s);
	return s;
}
#endif

