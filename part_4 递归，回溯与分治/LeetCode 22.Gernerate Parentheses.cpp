/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-08 23:21:59 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-08 23:45:12
 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void generateParentheses(int left, int right, string one,vector<string> &OUT_res){
    if(!left && left == right){
        OUT_res.push_back(one);
        return ;
    }
    if(left > 0){
        generateParentheses(left-1, right, one + "(",OUT_res);
    }
    if(left < right){
        generateParentheses(left, right-1, one + ")",OUT_res);
    }
}

int main()
{
    string IN_one;
    vector<string> OUT_res;
    generateParentheses(3, 3, IN_one, OUT_res);
    for(auto i : OUT_res)
    cout << i << endl;
}