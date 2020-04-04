/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 18:14:47 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:17:12
 *
 *华为机试在线训练--句子逆序
 */
#include <stack>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::stack;
using std::vector;
using std::string;

void reverse(string& str, size_t beg, size_t end)
{
    stack<char> ret;
    size_t length = 0;
    for(size_t i = beg; i != end; i++){
        ret.push(str[i]);
        ++length;
    }
    string retstr;
    while(length--){
        retstr.push_back(ret.top());
        ret.pop();
    }
    str.replace(str.begin()+beg, str.begin() + end, retstr);
    return ;
}

int main()
{
    string str;
    std::getline(cin, str);
    string tmp;
    size_t length = str.size();
    size_t beg = 0;
    size_t end = 0;
    reverse(str, beg, length);
    for(size_t i = 0; i != length; ++i){
        if(str[i] == ' '){
            if(beg != end){
                beg = end+1;
            }
            end = i;
            reverse(str, beg, end);
        }
    }
    if(str[length-1] != ' '){
        reverse(str, end+1, length);
    }
    
    cout << str << endl;
    return 0;
}