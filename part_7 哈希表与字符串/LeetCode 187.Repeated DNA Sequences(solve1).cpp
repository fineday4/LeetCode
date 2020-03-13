#include <stdio.h>

#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
		map<string, int> str_hash;
		vector<string> result;
		if(s.size() < 10)
			return result;
		for(int i = 0; i < s.size()-9; ++i){
			string tmp = s.substr(i, 10);
			++str_hash[tmp];
		}
		for(auto i : str_hash){
			if(i.second > 1)
				result.push_back(i.first);
		}
		return result;
    }
};

int main(){
	std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution solve;
	std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++){
		printf("%s\n", result[i].c_str());
	}
	return 0;
}
