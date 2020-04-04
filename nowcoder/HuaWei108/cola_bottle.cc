/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-26 12:12:08 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 12:13:46
 *
 *华为机试在线训练--汽水瓶
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t num;
    vector<size_t> vec_num;
    while(cin >> num){
        if(num/2)
            vec_num.push_back(num/2);
    }
    
    for(auto i : vec_num)
        cout << i << endl;
}