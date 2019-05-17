#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

inline std::vector<std::string> tokenize(const std::string &text, const char sep){
	std::istringstream is(text);
	std::vector<std::string> strings;
	strings.reserve(std::count(text.begin(), text.end(), sep));
	std::string part;
	while (getline(is, part, '\n')){
		strings.emplace_back(part);
	}
	return strings;
}

template<typename T>
inline size_t count(const std::vector<T> &vec, const T &el){
	return std::count(vec.begin(), vec.end(), el);
}

inline size_t count(const std::string &str, const char &el){
	return std::count(str.begin(), str.end(), el);
}
