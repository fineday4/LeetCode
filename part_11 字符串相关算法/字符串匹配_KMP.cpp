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
//* KMP中所体现的贪心和动态规划的思想：
//* 下面的循环是求next数组。
//* i是将要进行匹配的字符串范围的最后一个字符的索引，所以i的初始值为0，j是上一个字符串范围已经匹配到的字符的下标+1，由于初始时没有任何匹配，所以j的初始值为-1。*/
//! 必须要想清楚的几个规律就是（要动手计算一个next数组才可以想明白的，比如手算出ABCDABD的next数组[-1,0,0,0,0,1,2]）：
//! a. next数组存储的内容的含义：next[i]的意义就是第i字符已经匹配了next[i]个字符了，即该匹配下标为next[i]的字符了。
//! b. next[0] = -1为已知，
//! c. 当i > 0时，next[i]的值只有三种可能：
//!     1. 等于next[i-1]+1, 当pattern[j] == pattern[i];
//!     2. next[j]+1, do{j = next[j];}while(j != -1 && pattern[j] != pattern[i]);  要想理解这一步操作，需要首先理解并查集的思想。
//* 对c.2的解释，next数组的含义清楚了，当pattern[i] != pattern[j]的时候，next[i]的值就不能时next[i-1]+1（= ++j）了。
//* 也就是说pattern数组不能在继续向后匹配，而是要向前匹配（j减小的方向）。j如何减小？next[j]表示第j个元素

//* 清楚了上面的结论后，就可以有类似于动态规划的操作了。i = 0 -> length()-1 过程的状态转移方程：
//! next[i] = -1, i == 0,
//* j的变化体现的就是贪心的思想，而next的状态转移方程就体现了动态规划的思想。
//* 
    while(i < IN_pattern.size()-1){
        if(j == -1 || IN_pattern[j] == IN_pattern[i]){
            ++i;
            ++j;
            OUT_next.push_back(j);
        }else{
            j = OUT_next[j];   //! 问题：i没有回退只是j做了回退，如何确保IN_pattern[0...j-1] == IN_pattern[i-j, ...,i-1]的？？？？并查集思维!!
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