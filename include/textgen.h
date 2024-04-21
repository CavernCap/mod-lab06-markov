#pragma once
#include <deque>
#include <string>
#include <map>
#include <vector>

typedef std::deque<std::string> prefix;
class TextGen
{
private:
	std::map<prefix, std::vector<std::string>> statetab;
	prefix first_prefix;
public:
	void set(std::map<prefix, std::vector<std::string>> states);
	std::map<prefix, std::vector<std::string>> get();
	void CreateStatetabPrefixes(std::string& input_string, int prefixes_amount);
	std::string GenerateText(int generation_seed, int prefixes_amount);
};

