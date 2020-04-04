/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 18:17:05 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:17:26
 *
 *华为机试在线训练--字符串的连接最长路径查找
 */
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::sort;

int main()
{
	size_t n;
	cin >> n;
	string tmp;
	vector<string> vecstr;
	getline(cin, tmp);
	for(size_t j = 0; j != n; ++j){
		tmp.clear();
		getline(cin, tmp);
		vecstr.push_back(tmp);
	}
	sort(vecstr.begin(), vecstr.end());
	for(auto &j : vecstr){
		n-- == 0? cout << j : cout << j << endl; 
	}

	return 0;
}