#include <stdio.h>

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(
			std::vector<std::string>& strs) {
		 map<string, vector<string> > str_hash;
		 vector<std::vector<std::string> > result;
		 for(int i = 0; i < strs.size(); ++i){
			 string tmp = strs[i];
			 sort(tmp.begin(), tmp.end());
			 if(str_hash.find(tmp) == str_hash.end()){
				 str_hash[tmp].push_back(strs[i]);
			 }else{
				 if(find(str_hash[tmp].begin(), str_hash[tmp].end(), strs[i]) == str_hash[tmp].end()){
					 str_hash[tmp].push_back(strs[i]);
				 }
			 }
		 }
		 for(auto i : str_hash){
			 vector<string> tmp_vec;
			 for(auto j : i.second)
			 	tmp_vec.push_back(j);
			result.push_back(tmp_vec);
		 }
		 return result;
    }
};

int main(){
	std::vector<std::string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	Solution solve;
	std::vector<std::vector<std::string> > result 
		= solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}	
	return 0;
}
