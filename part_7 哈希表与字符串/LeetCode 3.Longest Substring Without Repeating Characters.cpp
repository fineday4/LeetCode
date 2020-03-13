#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
		int max_length = 0;
		vector<char> queue;
		//! 不错的实现
		for(int i = 0; i < s.size(); ++i){
			auto it_find = find(queue.begin(), queue.end(), s[i]);
			if(it_find == queue.end()){
				if(queue.size() >= max_length)
					++max_length;
				queue.push_back(s[i]);
			}else{
					queue.erase(queue.begin(), it_find + 1);
					queue.push_back(s[i]);
			}
		}
		return max_length;
    }
};

int main(){
	std::string s = "abcbadab";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));	
	return 0;
}
