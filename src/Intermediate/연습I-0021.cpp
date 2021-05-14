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

#define MAX_N 50

int T;
int N;
vector<pair<int, int>> points(MAX_N, make_pair(0, 0));

class Point {
public:
	int x;
	int y;

	static bool compare(Point& p1, Point& p2) {
		return p1.y * p2.x < p1.x* p2.y;
	}

	static bool compare(std::pair<int, int>& p1, std::pair<int, int>& p2) {
		return p1.second * p2.first < p1.first* p2.second;
	}
};

template<class T>
void selectionSort(vector<T>& list, int size, bool(*comp)(T, T)) {
	for (int i = 0; i < size; i++) {
		int max_index = i;

		for (int j = i + 1; j < size; j++) {
			if (comp(list[j], list[max_index])) {
				max_index = j;
			}
		}

		if (i != max_index) {
			T temp = list[i];
			list[i] = list[max_index];
			list[max_index] = temp;
		}
	}
}

template<class T> void insertionSort(vector<T>& list, int size, bool(*comp)(T, T)) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && comp(list[j], list[j - 1]); j--) {
			T temp = list[j];
			list[j] = list[j - 1];
			list[j - 1] = temp;
		}

	}
}

template<class T> void bubbleSort(vector<T>& list, int size, bool(*comp)(T, T)) {
	int end_index = size - 1;
	for (int i = 0; i < end_index; i++) {
		bool isSwapped = false;

		for (int j = end_index; j > i; j--) {
			if (comp(list[j], list[j - 1])) {
				T temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
				isSwapped = true;
			}
		}

		if (!isSwapped) {
			break;
		}
	}
}


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
		input_list = getInputList();
		N = std::atoi(input_list[0].c_str());

		//vector<pair<int, int>> points(N);
		for (int i = 0; i < N; i++) {
			input_list = getInputList();
			int x = std::atoi(input_list[0].c_str());
			int y = std::atoi(input_list[1].c_str());
			//points[i] = make_pair(x, y);

			points[i].first = x;
			points[i].second = y;

		}

		auto comp = [](pair<int, int> a, pair<int, int> b) -> bool {return a.second * b.first < a.first* b.second; };
		//std::sort(points.begin(), points.begin() + N, comp);
		//selectionSort<pair<int, int>>(points, N, comp);
		//bubbleSort<pair<int, int>>(points, N, comp);
		insertionSort<pair<int, int>>(points, N, comp);

		std::cout << "#" << test_case;

		/*for (int i = 0; i < N; i++) {
			std::cout << " " << points[i].first << "," << points[i].second;
		}*/
		for_each(points.begin(), points.begin() + N, [&](pair<int, int> a)->void {std::cout << SPACE_STR << a.first << "," << a.second; });

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

inline std::vector<string> split(std::string str, char delimiter) {
	vector<string> list;
	stringstream ss(str);
	string temp;

	while (std::getline(ss, temp, delimiter)) {
		list.push_back(temp);
	}

	return list;
}

inline std::vector<string> split(std::string s, std::string delimiter) {
	std::vector<string> list;

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



