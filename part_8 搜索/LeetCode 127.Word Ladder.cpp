/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-10 14:48:10 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-10 14:58:13
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> graph;
        cout << "beginWord: " << beginWord << endl;
        construct_graph(beginWord, wordList, graph);
        for(auto i : graph){
            cout << "key: " << i.first << endl;
            for(auto j : i.second){
                cout << " word: " << j;
            }
            cout << "-----------" << endl;
        }
        int res = BFS(beginWord, endWord, graph);
        return res;
    }
private:
    bool connect(const string &word1, const string &word2){
        int different = 0;
        for(int i =0; i < word1.size(); ++i){
            if(word1[i] != word2[i])
                ++different;
        }
        cout << "different: " << different << endl;
        return different == 1;
    }
    
    void construct_graph(string &begin_word, vector<string> &wordList, map<string, vector<string>> &graph){
        if(wordList.size() == 0 || begin_word.size() == 0)
            return ;
        wordList.push_back(begin_word);
        for(int idx = 0; idx < wordList.size(); ++idx){
            for(int iidx = 0; iidx < wordList.size(); ++iidx){
                if(connect(wordList[idx], wordList[iidx])){
                    cout << "true" << endl;
                    graph[wordList[idx]].push_back(wordList[iidx]);
                }
            }
        }
    }
    
    int BFS(string &begin_word, string &end_word, map<string, vector<string>> &graph){
        set<string> visited;
        queue<pair<string, int>> Q;
        Q.push(make_pair(begin_word, 1));
        visited.insert(begin_word);
        while(!Q.empty()){
            string search_word = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            for(auto i : graph[search_word]){
                if(visited.find(i) != visited.end())
                    continue;
                if(i == end_word)
                    return step+1;
                Q.push(make_pair(i, step+1));
                visited.insert(i);
            }
        }
        return -1;
    }
};

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    Solution sol;
    cout << "wordList" << endl;
    for(auto i : wordList){
        cout << " " << i;
    }
    cout <<endl;
    cout << "step: " << sol.ladderLength(beginWord,endWord, wordList) << endl;
}