/*
 * @Author: 爱上溜溜梅vincent(牛客大佬) 
 * @Date: 2017-06-14 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:57:55
 *
 *华为机试在线训练--识别有效的IP地址和掩码并进行分类统计
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//!字符串分割-->值得借鉴
void split(const string &IN_cstr, char IN_del, vector<string> &OUT_strdata){
    OUT_strdata.clear();
    stringstream ss(IN_cstr);
    string tok;
    while (getline(ss, tok, IN_del)){
        OUT_strdata.push_back(tok);
    }
}

//!IP的有效性判断
bool IPisvalid(const vector<string> &IN_csvec){
    if (IN_csvec.size() != 4){
        return false;
    }
    return true;
}

//! 掩码的有效性判断
bool Maskisvalid(const vector<string> &IN_csvec){
    bool zero = false;
    if (IN_csvec.size() != 4){
        return false;
    }
    //*思路：一个合法的掩码必须是这样的，255，0，在255和0之间的交界处只能是如下七个值：128,192,224,240,248,252,254，所以没有必要使用bitset，这样做就复杂了。
    for (int i = 0; i < 4; i++){
        if (zero == false){
            if (atoi(IN_csvec[i].c_str()) != 255){
                if (atoi(IN_csvec[i].c_str()) != 0 &&
                    atoi(IN_csvec[i].c_str()) != 128 &&
                    atoi(IN_csvec[i].c_str()) != 192 &&
                    atoi(IN_csvec[i].c_str()) != 224 &&
                    atoi(IN_csvec[i].c_str()) != 240 &&
                    atoi(IN_csvec[i].c_str()) != 248 &&
                    atoi(IN_csvec[i].c_str()) != 252 &&
                    atoi(IN_csvec[i].c_str()) != 254){
                    return false;
                }
                else{
                    zero = true;
                }
            }
        }
        else{
            if (atoi(IN_csvec[i].c_str()) != 0){
                return false;
            }
        }
    }
    if (atoi(IN_csvec[3].c_str()) == 255){
        return false;
    }
    return true;
}
 
int main(){
    vector<int> ret(7, 0);
    string str;
    vector<string> svec;
    vector<string> ip;
    vector<string> mask;
    while (cin>> str){
        split(str, '~',svec);
        split(svec[0], '.',ip);
        split(svec[1], '.',mask);
        if (Maskisvalid(mask) && IPisvalid(ip)){
            if (atoi(ip[0].c_str()) >= 1 && atoi(ip[0].c_str()) <= 126){
                ++ret[0];
                if (atoi(ip[0].c_str()) == 10)
                    ++ret[6];
            }
            else if (atoi(ip[0].c_str()) >= 128 && atoi(ip[0].c_str()) <= 191){
                ++ret[1];
                if (atoi(ip[0].c_str()) == 172){
                    if (atoi(ip[1].c_str()) >= 16 && atoi(ip[1].c_str()) <= 31)
                        ++ret[6];
                }
            }
            else if (atoi(ip[0].c_str()) >= 192 && atoi(ip[0].c_str()) <= 223){
                ++ret[2];
                if (atoi(ip[0].c_str()) == 168)
                    ++ret[6];
            }
            else if (atoi(ip[0].c_str()) >= 224 && atoi(ip[0].c_str()) <= 239){
                ++ret[3];
            }
            else if (atoi(ip[0].c_str()) >= 240 && atoi(ip[0].c_str()) <= 255){
                ++ret[4];
            }
        }
        else{
            ret[5]++;
        }
    }
    cout << ret[0] << " " << ret[1] << " " << ret[2] << " " << ret[3] << " " << ret[4] << " " << ret[5] << " " << ret[6] << endl;
    return 0;
}