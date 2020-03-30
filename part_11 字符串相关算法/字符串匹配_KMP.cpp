/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-22 10:17:34 
 * @Last Modified by:   xuhuanhuan 
 * @Last Modified time: 2020-03-22 10:17:34 
 */

#include <iostream>
#include <vector>

using namespace std;

void getNext(const string &IN_pattern, vector<int> &OUT_next){
    OUT_next.push_back(-1);
    int i = 0;  //*范围
    int j = -1; //*索引

/*
//* KMP中所体现的贪心算法：
//* 下面的循环是求next数组。
//* i是将要进行匹配的字符串范围的最后一个字符的索引，所以i的初始值为0，j是上一个字符串范围已经匹配到的字符的下标+1，由于初始时没有任何匹配，所以j的初始值为-1。*/
//! 必须要想清楚的一个规律就是（要动手计算一个next数组才可以想明白的，比如手算出ABCDABD的next数组[-1,0,0,0,0,1,2]）：next[0] = -1为已知，
//! 当i > 0时，next[i]的值只有三种可能：
//! 1. 等于next[i-1]+1, 当pattern[j] == pattern[i];
//! 2. 等于1, 当pattern[j] != pattern[i] && pattern[0] == pattern[i];
//! 3. 等于0, 当pattern[j] != pattern[i] && pattern[0] != pattern[i];
//* 清楚了上面的结论后，就可以有类似于动态规划的操作了。i = 0 -> length()-1 过程的状态转移方程：
//! next[i] = -1, i == 0,
//! next[i] = (pattern[j] == pattern[i]? ++j : (pattern[i] == pattern[0]? 1 : 0)) i > 0
//* 
    while(i < IN_pattern.size() - 1) {
        if (j == -1 || IN_pattern[i] == IN_pattern[j]) { //*范围只有在索引=-1或者[i] == [j]时才++
            i++;
            j++;
            OUT_next.push_back(j);
        } else {
            j = OUT_next[j];
        }
    }
}

bool kmp(const string& IN_pattern, const string& IN_str){
    vector<int> OUT_next;
    getNext(IN_pattern, OUT_next);
    int j = 0;
    for(int i = 0; i < IN_str.size(); ++i){
        if(IN_pattern[j] == IN_str[i]){
            ++j;
            if(j == IN_pattern.size())
                return true;
        }else{
            j = j-OUT_next[j]+1;
        }
    }
    return false;
}

int main()
{
    const string pattern = "ABCDBD";
    const string str = "ABCDBD";
    if(kmp(pattern, str)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
}