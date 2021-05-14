#include <iostream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

#define MAX_VALUE 10000
int T;
int A, B;
bool isPrime[MAX_VALUE + 1];

void sieveOfEratosthenes(bool* isPrime, int size);
vector<string> split(string str, char delimiter);
vector<string> split2(string s, string delimiter);

int main(int argc, char** argv) {

	string input;

	std::getline(std::cin, input);

	T = atoi(input.c_str());

	sieveOfEratosthenes(isPrime, sizeof(isPrime));

	for (int test_case = 1; test_case <= T; test_case++) {
		std::getline(std::cin, input);

		vector<string> line_vector = split(input, ' ');
		//vector<string> line_vector = split2(input, " ");

		A = std::atoi(line_vector[0].c_str());
		B = std::atoi(line_vector[1].c_str());

		
		int count = 0;
		for (int i = A; i <= B; i++) {
			if (isPrime[i]) {
				count++;
			}
		}

		cout << "#" << test_case << " " << count << endl;
	}

	return 0;
}

void sieveOfEratosthenes(bool* isPrime, int size) {
	for (int i = 2; i < size; i++) {
		isPrime[i] = true;
	}
	//memset(isPrime + 2, true, size - 2);
	isPrime[0] = false;
	isPrime[1] = false;


	for (int i = 2; i <= sqrt(size); i++) {
		if (!isPrime[i]) {
			continue;
		}

		for (int j = 2 * i; j < size; j += i) {
			isPrime[j] = false;
		}
	}
}

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

vector<string> split2(string s, string delimiter) {
	vector<string> internal;

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		internal.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	internal.push_back(s);

	return internal;
}
