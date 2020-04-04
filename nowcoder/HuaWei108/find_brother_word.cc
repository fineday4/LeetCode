/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-27 20:23:31 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-27 22:45:17
 *
 *
 */
 #if 1  //! 输入后在执行查询的思路
#include<iostream> 
#include<string> 
#include<vector> 
#include<algorithm> 

using namespace std; 
   
bool is_brother(string _lhs, string _rhs){
    sort(_lhs.begin(), _lhs.end());
    sort(_rhs.begin(), _rhs.end());
    if(_lhs == _rhs)
        return true;
    return false;
}

int main()
{
    int num;
    while(cin >> num){
        vector<string> word_list;
        vector<string> word_brother;
        for(int i = 0; i < num; ++i){
            string word;
            cin >> word;
            word_list.push_back(word);
        }
        string search_word;
        int search_idx;
        cin >> search_word >> search_idx;
        for(auto &i : word_list){
            if(i != search_word && is_brother(i, search_word)){
                word_brother.push_back(i);
            }
        }
        sort(word_brother.begin(), word_brother.end());
        size_t len = word_brother.size();
        cout << len << endl;
        if(search_idx > 0 && search_idx <= len)
            cout << word_brother[search_idx-1] << endl;
    }
}
#endif

#if 0
#include<map>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    while(cin >> num){
        map<vector<size_t>, vector<string> > diction;
        for(size_t idx = 0; idx < num; ++idx){
            string word;
            cin >> word;
            vector<size_t> word_nature(26,0);
            for(auto i : word){
                ++word_nature[i - 'a'];
            }
            auto find_idx = find(diction[word_nature].begin(), diction[word_nature].end(), word);//TODO:
            if(find_idx == diction[word_nature].end())
                diction[word_nature].push_back(word);
        }
        for(auto &i : diction){
            sort(i.second.begin(), i.second.end());
        }
        string search_word;
        size_t search_idx;
        cin >> search_word >> search_idx;
        vector<size_t> word_nature(26,0);
        for(auto i : search_word){
            ++word_nature[i - 'a'];
        }     
        auto search_in_it = find(diction[word_nature].begin(), diction[word_nature].end(), search_word);
        size_t search_in_idx = search_in_it - diction[word_nature].begin();
        if(search_in_it != diction[word_nature].end()){
            cout << diction[word_nature].size()-1 << endl;
            if(search_idx <= diction[word_nature].size() && search_idx > 0){
                if(search_idx-1 < search_in_it - diction[word_nature].begin()){
                    #if 1
                    cout << "=====IF=========" << endl;
                    for(auto i : diction[word_nature]){
                        cout << i << " --- ";
                    }
                    cout << endl;
                    #endif
                    cout << diction[word_nature][search_idx-1] << endl;
                }else{
                    if(search_idx < diction[word_nature].size())
                    {
                        #if 1
                        cout << "========ELSE======" << endl; 
                        for(auto i : diction[word_nature]){
                            cout << i << " --- ";
                        }
                        cout << endl;
                        #endif
                        cout << diction[word_nature][search_idx] << endl;
                    }
                }
            }
        }else{
            cout << diction[word_nature].size() << endl;
            if(search_idx <= diction[word_nature].size() && search_idx > 0){
                #if 1
                for(auto i : diction[word_nature]){
                    cout << i << " --- ";
                }
                cout << endl;
                #endif
                cout << diction[word_nature][search_idx-1] << endl;
            }
        }
    }
    return 0;
}
#endif