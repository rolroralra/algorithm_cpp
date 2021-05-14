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


int T;
int N;

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
		//std::getline(std::cin, input);
		//input_list = getInputList();
		//N = std::atoi(input_list[0].c_str());

		/**************************************
		* Implementation for Algorithm Problem
		***************************************/
		int A, B, C, D;

		input_list = getInputList();
		A = std::atoi(input_list[0].c_str());
		B = std::atoi(input_list[1].c_str());
		C = std::atoi(input_list[2].c_str());
		D = std::atoi(input_list[3].c_str());


		int result = 0;
		int i = A;
		while (i <= B) {
			if (i % C == D) {
				result++;
				i += C;
			}
			else {
				i++;
			}
		}
		/*int A_mod_C = A % C;
		int B_mod_C = B % C;
		int scale = (B - A + 1) / C;

		if (scale == 0) {
			if (A_mod_C > B_mod_C) {
				if (A_mod_C <= D && D < C) {
					scale++;
				}
				else if (0 <= D && D <= B_mod_C) {
					scale++;
				}
			}
			else {
				if (A_mod_C <= D && D <= B_mod_C) {
					scale++;
				}
			}
		}
		else {
			if (D <= B_mod_C) {
				scale++;
			}
		}*/

		std::cout << "#" << test_case << SPACE_STR << result << endl;
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



