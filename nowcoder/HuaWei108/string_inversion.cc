/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 18:13:21 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:13:43
 *
 *华为机试在线训练--字符串反转
 */
#include <iostream>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::stack;

int main()
{
    stack<char> reser;
    char c;
    size_t length = 0;
    while(cin >> c){
        reser.push(c);
        ++length;
    }
    for(size_t idx = 0; idx != length; ++idx){
        cout << reser.top();
        reser.pop();
    }
    
    return 0;
}