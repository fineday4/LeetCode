/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 18:18:17 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:18:43
 *
 *华为机试在线训练--int型变量在内存中存储时1的个数
 */
#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main()
{
    unsigned n;
    cin >> n;
    bitset<64> bnum(n);
    cout << bnum.count();
    
    return 0;
}