#include <iostream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

vector<string> split(string str, char delimiter);
vector<string> split2(string s, string delimiter);

#define TEST
#define MAX_VALUE 10000
#define MIN_VALUE -10000
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

	std::getline(std::cin, input);

	T = std::atoi(input.c_str());

	for (int test_case = 1; test_case <= T; test_case++) {
		std::getline(std::cin, input);

		vector<string> input_list = split(input, ' ');
		//vector<string> line_vector = split2(input, " ");

		/**************************************
		* Implementation for Algorithm Problem
		***************************************/

		N = std::atoi(input_list[0].c_str());

		std::getline(std::cin, input);
		input_list = split(input, ' ');

		int result = std::atoi(input_list[0].c_str());
		for (int i = 1; i < input_list.size() && result < MAX_VALUE; i++) {
			int number = std::atoi(input_list[i].c_str());
			if (number > result) {
				result = number;
			}
		}

		printf("#%d %d\n", test_case, result);
		//std::cout << "#" << test_case << " " << result << endl;
	}

#ifdef TEST
	inputFileStream.close();
#endif

	return 0;
}

vector<string> split(string str, char delimiter) {
	vector<string> list;
	stringstream ss(str);
	string temp;

	while (std::getline(ss, temp, delimiter)) {
		list.push_back(temp);
	}

	return list;
}

vector<string> split2(string s, string delimiter) {
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
