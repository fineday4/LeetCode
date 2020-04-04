/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 18:20:31 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:20:51
 *
 *华为机试在线训练--坐标移动
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

void string2vector(const string &IN_cstr, vector<string> & OUT_vecstr)
{
    size_t start_idx = 0;
    size_t end_idx = IN_cstr.find_first_of(";", start_idx);
    while(end_idx != std::string::npos && start_idx < IN_cstr.size()){
        if(start_idx < end_idx)
            OUT_vecstr.push_back(IN_cstr.substr(start_idx, end_idx - start_idx));
    
        start_idx = end_idx + 1 < IN_cstr.size()? end_idx + 1 : IN_cstr.size();
        end_idx = IN_cstr.find_first_of(";", start_idx);
     }
}

bool isLegal(const string &IN_cstr)
{
    size_t len = IN_cstr.size();
    if(len == 3){
        if((IN_cstr[0] == 'A' || IN_cstr[0] == 'D' || IN_cstr[0] == 'W' || IN_cstr[0] == 'S') && (IN_cstr[1] >= '0' && IN_cstr[1] <= '9')&& (IN_cstr[2] >= '0' && IN_cstr[2] <= '9'))
            return true;
    }else if(len == 2){
        if((IN_cstr[0] == 'A' || IN_cstr[0] == 'D' || IN_cstr[0] == 'W' || IN_cstr[0] == 'S') && (IN_cstr[1] >= '0' && IN_cstr[1] <= '9'))
            return true;
    }
    return false;
}

int main()
{
    string str;
    while(cin >> str){
        
    vector<string> res;
    string2vector(str, res);
    int x = 0, y = 0;
    for(auto &i : res){
        if(isLegal(i)){
            string tmp;
            std::istringstream iss(i.substr(1));
            int pos;
            iss >> pos;
                if(i[0] == 'A'){
                    x -= pos;
                }else if(i[0] == 'D'){
                    x += pos;
                }else if(i[0] == 'W'){
                    y += pos;
                }else if(i[0] == 'S'){
                    y -= pos;
                }
        }
    }
    printf("%d,%d\n", x, y);
    }
    return 0;
}