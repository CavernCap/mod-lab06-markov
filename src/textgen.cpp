// Copyright 2024 Kapochkin Mikhail
#include "textgen.h"
#include <sstream>
#include <random>

void TextGen::set(std::map<prefix, std::vector<std::string>> states) {
    statetab = states;
}
std::map<prefix, std::vector<std::string>> TextGen::get() {
    return statetab;
}
void TextGen::CreateStatetabPrefixes(std::string& inpstring, int prefamount) {
    std::istringstream input_text(inpstring);
    prefix current_prefix;
    std::string word;

    for (int i = 0; i < prefamount; i++) {
        input_text >> word;
	    current_prefix.push_back(word);
	}

    first_prefix = current_prefix;
    while (input_text >> word) {
	    statetab[current_prefix].push_back(word);
	    current_prefix.push_back(word);
	    current_prefix.pop_front();
	}
}
std::string TextGen::GenerateText(int generation_seed, int MAXGEN) {
    std::mt19937 mt(time(nullptr));
    int randomNumber;
    std::string text_for_output;
    prefix current_prefix = first_prefix;
    std::string new_prefix;
    for (auto prefIt = current_prefix.begin();prefIt != current_prefix.end(); prefIt++) {
        text_for_output += *prefIterator + " ";
        MAXGEN--;
	}
    for (int i = 0; i < MAXGEN; i++) {
	    if (statetab.find(current_prefix) == statetab.end()) break;
	    randomNumber = mt() % statetab[current_prefix].size();
	    new_prefix = statetab[current_prefix][randomNumber];
	    text_for_output += new_prefix + " ";
	    current_prefix.push_back(new_prefix);
	    current_prefix.pop_front();
	}
    return text_for_output;
}
