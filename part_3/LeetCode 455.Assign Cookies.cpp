#include <stdio.h>

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int g_idx = 0, s_idx = 0;
		while(g_idx < g.size() && s_idx < s.size()){
			if(g[g_idx] <= s[s_idx])
				++g_idx;
			++s_idx;
		}
		return g_idx;
    }
};

int main(){
	Solution solve;
	std::vector<int> g;
	std::vector<int> s;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);	
	printf("%d\n", solve.findContentChildren(g, s));
	return 0;
}
