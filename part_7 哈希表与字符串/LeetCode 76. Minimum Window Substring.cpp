
#include <stdio.h>

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){
		for(int i = 0; i < vec_t.size(); ++i){
			if(map_s[vec_t[i]] < map_t[vec_t[i]])
				return false;
		}
		return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        vector<int> vec_t;
		static int MAX_CHAR = 128;
		int map_s[MAX_CHAR] = {0};
		int map_t[MAX_CHAR] = {0};
		string result;
		for(int i = 0; i < t.size(); ++i){
			++map_t[t[i]];
		}
		for(int i = 0; i < MAX_CHAR; ++i)
			if(map_t[i])
				vec_t.push_back(i);

		int window_begin = 0;
		for(int i = 0; i < s.size(); ++i){
			++map_s[s[i]];
			while(window_begin < i){
				char begin_c = s[window_begin];
				if(map_t[begin_c] == 0)
					++window_begin;
				else if(map_s[begin_c] > map_t[begin_c]){
					--map_s[begin_c];
					++window_begin;
				}else{
					break;
				}
			}
			if(is_window_ok(map_s, map_t, vec_t)){
				int window_len = i - window_begin + 1;
				if(result.size() == 0 || result.size() > window_len)
					result = s.substr(window_begin, window_len);
			}
		}
		return result;
    }
};

int main(){
	
	Solution solve;
	std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("MADOBCCABEC", "ABCC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("aa", "aa");
	printf("%s\n", result.c_str());
	
	return 0;	
}
