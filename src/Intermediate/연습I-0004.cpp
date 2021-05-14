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

#define MAX_VALUE 10000
int T;

int main(int argc, char** argv) {

	//string filePath = "sample_input.txt";

	//// read File
	//ifstream inputFileStream;
	//inputFileStream.open(filePath, ios_base::in);
	////ifstream openFile(filePath);
	//if (inputFileStream.is_open()) {
	//	std::cin.rdbuf(inputFileStream.rdbuf());  // swap
	//}

	string input;

	std::getline(std::cin, input);

	T = std::atoi(input.c_str());

	int a1, a2, b1, b2;
	for (int test_case = 1; test_case <= T; test_case++) {
		std::getline(std::cin, input);

		vector<string> input_list = split(input, ' ');
		//vector<string> line_vector = split2(input, " ");

		a1 = std::atoi(input_list[0].c_str());
		a2 = std::atoi(input_list[1].c_str());
		b1 = std::atoi(input_list[2].c_str());
		b2 = std::atoi(input_list[3].c_str());


		double result = (double)(a1 * b2 + a2 * b1) / (a2 * b2);
		printf("#%d %.13lf\n", test_case, result);

		//std::cout << "#" << test_case << " " << result << endl;
	}

	//inputFileStream.close();
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
