#include <stdio.h>

#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
		int hash_char[128] = {0};
		for(int i = 0; i < s.size(); ++i){
			++hash_char[s[i]];
		}
		int max_length = 0;
		int flag = 0;
		for(int i = 0; i < 128; ++i){
			if(hash_char[i]%2 == 0){
				max_length += hash_char[i];
			}else if(hash_char[i]%2 == 1){
				flag = 1;
				max_length += hash_char[i] - 1;
			}
		}
		return max_length + flag;
    }
};

int main(){
	std::string s = "abccccddaa";
	Solution solve;
	printf("%d\n", solve.longestPalindrome(s));
	return 0;
}
