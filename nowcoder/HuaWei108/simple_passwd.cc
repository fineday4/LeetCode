/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-26 10:11:32 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 10:11:56
 *
 *华为机试在线训练--简单密码破解
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string paswd;
    vector<string> res;
    while(cin >> paswd){
        size_t len = paswd.size();
        for(size_t idx = 0; idx < len; ++idx){
            if(paswd[idx] >= 'A' && paswd[idx] <= 'Z'){
                if(paswd[idx] == 'Z')
                    paswd[idx] = 'a';
                else
                    paswd[idx] = paswd[idx] + 33;
            }else if(paswd[idx] >= 'a' && paswd[idx] <= 'c')
                paswd[idx] = '2';
            else if(paswd[idx] >= 'd' && paswd[idx] <= 'f')
                paswd[idx] = '3';
            else if(paswd[idx] >= 'g' && paswd[idx] <= 'i')
                paswd[idx] = '4';
            else if(paswd[idx] >= 'j' && paswd[idx] <= 'l')
                paswd[idx] = '5';
            else if(paswd[idx] >= 'm' && paswd[idx] <= 'o')
                paswd[idx] = '6';
            else if(paswd[idx] >= 'p' && paswd[idx] <= 's')
                paswd[idx] = '7';
            else if(paswd[idx] >= 't' && paswd[idx] <= 'v')
                paswd[idx] = '8';
            else if(paswd[idx] >= 'w' && paswd[idx] <= 'z')
                paswd[idx] = '9';
        }
        res.push_back(paswd);
        paswd.clear();
    }
    for(auto &i: res)
        cout << i << endl;
}