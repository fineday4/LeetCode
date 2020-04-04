/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 23:10:50 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 00:07:01
 *
 *华为机试在线训练--密码验证合格程序
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string tmp;
    vector<string> res_str;
    while(cin >> tmp){
        if(tmp.size() > 8){
            size_t B_word = 0, l_word = 0, num = 0, other = 0;
            for(size_t i = 0; i < tmp.size(); ++i){
                if(tmp[i] >= 'a' && tmp[i] <= 'z')
                    l_word = 1;
                else if(tmp[i] >= 'A' && tmp[i] <= 'Z')
                    B_word = 1;
                else if(tmp[i] >= '0' && tmp[i] <= '9')
                    num = 1;
                else
                    other = 1;
            }
            if(B_word + l_word + num + other < 3)
                res_str.push_back("NG");
            else{
            //! 确定长度的子串匹配问题的解决办法
                bool is_set = false;
                for(size_t i = 0; i <= tmp.size() - 6; ++i){
                    for(size_t j = i+3; j < tmp.size()-2; ++j){
                        if(tmp[i] == tmp[j] && tmp[i+1] == tmp[j+1] && tmp[i+2] == tmp[j+2]){
                            res_str.push_back("NG");
                            is_set = true;
                            break;
                        }
                    }
                    if(is_set) break;
                }
                if(!is_set)
                    res_str.push_back("OK");
            }
        }else{
            res_str.push_back("NG");
        }
    }
    for(auto &i : res_str)
        cout << i << endl;
}

#if 0
//! 下面的程序是牛客上非常完美的解答
//* 链接：https://www.nowcoder.com/questionTerminal/184edec193864f0985ad2684fbc86841?f=discussion
//* 来源：牛客网

#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        int flag[4] = {0};
        if(str.size() <= 8) goto NG;
        for(int i = 0; i < str.size(); ++i)
            if(str[i] >= 'a' && str[i] <= 'z') flag[0] = 1;
            else if(str[i] >= 'A' && str[i] <= 'Z') flag[1] = 1;
            else if(str[i] >= '0' && str[i] <= '9') flag[2] = 1;
            else flag[3] = 1;
        if(flag[0] + flag[1] + flag[2] + flag[3] < 3) goto NG;
        for(int i = 0; i <= str.size()-6; i++)
            for(int j = i+3;j < str.size();j++)
                if(str[i] == str[j] && str[i+1] == str[j+1] &&str[i+2] == str[j+2]) goto NG;
        OK:
        cout << "OK" << endl;continue;
        NG:
        cout << "NG" << endl;
    }
    return 0;
}
#endif