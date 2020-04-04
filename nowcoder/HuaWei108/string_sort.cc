/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-27 16:44:41 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-27 20:20:58
 *
 *华为机试在线训练--字符串排序
 */

#if 0
/*
*这个方法太聪明了（来自牛客），思路是这样的（动态规划的思想）：将s的字母按照（j = 0 -> 26）从小到大的序
*插入到tempChar中,然后在将s中的字母全部替换为tempChar的对应下标的字母即可。
*/
#include<vector>
#include<iostream>
#include<string>
 
using namespace std;
 
int main()
{
    string s;
    vector<char> tempChar;
    while(getline(cin,s))
    {
        tempChar.clear();
        int len = s.size();
        for(int j=0; j<26; j++)
        {
            for(int i=0; i<len; i++)
            {
                if(s[i]-'a'==j||s[i]-'A'==j)
                {
                    tempChar.push_back(s[i]);
                }
            }
        }
        for(int i=0,k=0;(i<len)&&k<tempChar.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
                s[i]=tempChar[k++];
        }
        cout<<s<<endl;
    }
    return 0;
}

#endif
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string word;
    while(getline(cin,word)){
        for(size_t idx = 0; idx < word.size() + 1; ++idx){
            if(!isalpha(word[idx])){
                continue;
            }
            char min_char = word[idx];
            int min_idx = idx;
            for(size_t iidx = idx + 1; iidx < word.size(); ++iidx){
                if(isalpha(word[iidx])){
                    //! 如何不区分大小写字母比较大小
                    if((islower(min_char) && islower(word[iidx]) &&(min_char - word[iidx] > 0))||
                        (islower(min_char) && isupper(word[iidx]) &&(min_char - word[iidx] - 32 > 0))||
                        (isupper(min_char) && islower(word[iidx]) &&(min_char - word[iidx] + 32 > 0))
                        ||(isupper(min_char) && isupper(word[iidx]) &&(min_char - word[iidx] > 0))){
                        min_char = word[iidx];
                        min_idx = iidx;
                     }
                 }
            }
            if(min_idx != idx){
                size_t move_idx = min_idx;
                while(move_idx > idx){
                    if(isalpha(word[move_idx])){
                        for(size_t move_iidx = move_idx -1; move_iidx >= idx; --move_iidx){
                            if(isalpha(word[move_iidx])){
                                word[move_idx] = word[move_iidx];
                                move_idx = move_iidx;
                                break;
                            }
                        }
                    }
                }
                word[idx] = min_char;
            }
         }
        cout << word << endl;
        word.clear();
    }
    return 0;
}