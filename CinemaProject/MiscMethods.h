#pragma once
#include <string>
#include <algorithm>
#include <cctype>

class MiscMethods
{
public:
	static std::string to_upper(const std::string& input) {
        std::string uppercased = input;
        std::transform(uppercased.begin(), uppercased.end(), uppercased.begin(), ::toupper);
        return uppercased;
    }
};

