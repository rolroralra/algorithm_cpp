#ifndef ALGORITHM_CPP_STRING_LIB_H
#define ALGORITHM_CPP_STRING_LIB_H

#include <algorithm>
#include <cctype>
#include <locale>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> split(std::string str, char delimiter);
std::vector<std::string> split(std::string s, std::string delimiter);

inline void ltrim(std::string& s);
inline void rtrim(std::string& s);
inline void trim(std::string& s);
inline std::string ltrim_copy(std::string s);
inline std::string rtrim_copy(std::string s);
inline std::string trim_copy(std::string s);

#endif //ALGORITHM_CPP_STRING_LIB_H
