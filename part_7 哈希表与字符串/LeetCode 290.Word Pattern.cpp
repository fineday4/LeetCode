#include <stdio.h>

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
		map<string, char> word_map;
		str.push_back(' ');
		int pos = 0;
		int used_char[128] = {0};
		string word;
		for(int i = 0; i < str.size(); ++i){
			if(str[i] == ' '){
				if(pos == pattern.size())
					return false;
				if(word_map.find(word) == word_map.end()){
					if(used_char[pattern[pos]])
						return false;
					word_map[word] = pattern[pos];
					used_char[pattern[pos]] = 1;
				}else{
					if(word_map[word] != pattern[pos])
						return false;
				}
				++pos;
				word.clear();
			}else{
				word.push_back(str[i]);
			}
		}
		if(pos != pattern.size())
			return false;
			
		return true;
    }
};

int main(){
	std::string pattern = "abba";
	std::string str = "dog cat cat dog";
	Solution solve;
	printf("%d\n", solve.wordPattern(pattern, str));
	return 0;
}
