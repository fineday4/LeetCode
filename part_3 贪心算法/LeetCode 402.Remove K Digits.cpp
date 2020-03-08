
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
		if(num.size() == 0)
			return num;
		vector<char> stack_nums;
		for(int idx = 0; idx < num.size(); ++idx){
			while(stack_nums.size() && stack_nums.back() > num[idx] && k > 0){
				stack_nums.pop_back();
				--k;
			}
			if(num[idx] != '0' || stack_nums.size() != 0){
				stack_nums.push_back(num[idx]);
			}
		}
		while(k){
			stack_nums.pop_back();
			--k;
		}
		string res;
		cout << "stack_nums: "; 
		for(auto i : stack_nums){
			cout << i;
			res.push_back(i);
		}
		cout << endl;
		return res;
    }
};

int main(){
	Solution solve;
	std::string result = solve.removeKdigits("1432219", 3);
	printf("%s\n", result.c_str());
	std::string result2 = solve.removeKdigits("100200", 1);
	printf("%s\n", result2.c_str());
	return 0;
}
