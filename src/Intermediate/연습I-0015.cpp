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

//#define TEST
//#define STRING_TRIM

using namespace std;

/*************************************************************************/
/* Libarary Function
/*************************************************************************/
std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);
std::vector<std::string> getInputListFromInputstreamLine(std::istream& inputStream, char delimiter);
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

#define MAX_N 11
#define SPACE_STR " "
#define STAR_STR "*"
#define SPACE_CHAR ' '
#define STAR_CHAR '*'


int T;
int N;
int arr[MAX_N][MAX_N];

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

	std::getline(std::cin, input);
	input_list = split(input, SPACE_STR);
	//input_list = getInputListFromInputstreamLine(std::cin, SPACE_CHAR);
	T = std::atoi(input_list[0].c_str());

	for (int test_case = 1; test_case <= T; test_case++) {
		//std::getline(std::cin, input);
		input_list = getInputListFromInputstreamLine(std::cin, SPACE_STR);
		N = std::atoi(input_list[0].c_str());

		/**************************************
		* Implementation for Algorithm Problem
		***************************************/
		for (int i = 0; i < N; i++) {
			input_list = getInputListFromInputstreamLine(std::cin, SPACE_STR);

			for (int j = 0; j < N; j++) {
				arr[i][j] = std::atoi(input_list[j].c_str());
			}
		}

		std::cout << "#" << test_case << SPACE_STR;

		int mid_index = N / 2;

		int scale = 1;
		int inc = -1;
		int x, y;

		x = y = mid_index;

		std::cout << arr[x][y] << SPACE_STR;
		while (scale < N) {
			for (int row = 0; row < scale; row++) {
				x += inc;
				std::cout << arr[x][y] << SPACE_STR;
			}

			for (int col = 0; col < scale; col++) {
				y += -1 * inc;
				std::cout << arr[x][y] << SPACE_STR;
			}

			inc *= -1;
			scale++;
		}
		scale--;
		for (int row = 0; row < scale; row++) {
			x += inc;
			std::cout << arr[x][y] << SPACE_STR;
		}

		std::cout << endl;

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



