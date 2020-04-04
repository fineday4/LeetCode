/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 18:12:08 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:12:30
 *
 *华为机试在线训练--数字颠倒
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
    unsigned num;
    cin >> num;
    vector<unsigned> res;
    if(num == 0){
        res.push_back(0);
    }else{
        while(num){
            res.push_back(num%10);
            num = num/10;
        }
    }
    for(auto i :  res){
        cout << i;
    }
}