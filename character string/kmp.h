//reference:https://www.cnblogs.com/ZuoAndFutureGirl/p/9028287.html
#pragma once
#include <vector>
#include <string>
#include <iostream>
std::vector<int> getNext(const std::string& pattern) {
	std::vector<int> next(pattern.length(), -1);
	int k = -1, j = 0;
	while (j < pattern.length()-1) {
		if (k == -1 || pattern[k] == pattern[j]) {
			++k;
			++j;
			if (pattern[j] != pattern[k])//it is a trick
				next[j] = k;
			else
				next[j] = next[k];

		}
		else {
			k = next[k];
		}
	}
	return next;
}
int kmp_1st(const std::string& text, const std::string& pattern) {
	//find the first index of matched pattern
  int len_text = text.length(), len_pattern = pattern.length();
	if (len_text < len_pattern) return -1;
	int i = 0, j = 0;
	std::vector<int> next = getNext(pattern);
	while (i < len_text&& j<len_pattern) {
		
		if (j == -1 || text[i] == pattern[j]) { ++i; ++j; }
		else {
			j = next[j];
		}
	}
	if (j == len_pattern) return i - j;
	return -1;
};

/*
int main(int argc, char** argv) {
	std::string text = "wo ai 6niaia 14yoabdabdu!", pattern = "abdabd";
	//std::cout << pattern.length();
	std::vector<int> next=getNext(pattern);
	//std::vector<int> next(pattern.length(), -1);
	std::cout << next.size()<<std::endl;
	for (auto& ele : next)std::cout << ele<<std::endl;
	std::cout << kmp_1st(text, pattern) << std::endl;
	std::cin.get();
	return 0;
}
*/
