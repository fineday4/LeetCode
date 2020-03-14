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
        construct_graph(beginWord, wordList, graph);
        int res = BFS(beginWord, endWord, graph);
        return res;
    }
private:
    bool connect(const string &word1, const string &word2){
        int diff = 0;
        for(int i = 0; i < word1.size() && i < word2.size(); i++){
            if(word1[i] != word2[i])
                ++diff;
        }
        return diff == 1;
    }
    
    void construct_graph(string &begin_word, vector<string> &wordList, map<string, vector<string>> &graph){
        if(wordList.size() == 0)
            return;
        wordList.push_back(begin_word);
        for(auto word1 : wordList){
            for(auto word2 : wordList){
                if(connect(word1, word2)){
                    graph[word1].push_back(word2);
                }
            }
        }
    }
    
    int BFS(string &begin_word, string &end_word, map<string, vector<string>> &graph){
        set<string> visited;
        queue<pair<string, int> > Q;
        Q.push(make_pair(begin_word, 1));
        visited.insert(begin_word);
        while(!Q.empty()){
            int step = Q.front().second;
            string word = Q.front().first;
            Q.pop();
            for(auto i : graph[word]){
                if(i == end_word){
                    return step+1;
                }else if(visited.find(i) == visited.end()){
                    visited.insert(i);
                    Q.push(make_pair(i, step+1));
                }
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
    cout << "wordList: " << endl;
    for(auto i : wordList){
        cout << " " << i;
    }
    cout <<endl;
    cout << "step: " << sol.ladderLength(beginWord,endWord, wordList) << endl;
}