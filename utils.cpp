#include "utils.hpp"

std::vector<std::string> parse_input(std::string text){
	int n = text.size();
	int i;
	std::string space_delim = " ";
	std::size_t pos;
	std::vector<std::string> words;
	while ((pos = text.find(space_delim)) != std::string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delim.length());
    }
    words.push_back(text);
    return words;
}

float min(float a, float b){
	if(a<b){
		return a;
	}else{
		return b;
	}
}