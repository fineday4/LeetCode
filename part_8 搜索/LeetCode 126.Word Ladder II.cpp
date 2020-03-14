/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-10 17:14:56 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-10 18:46:23
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Item{
    string word;
    int parent_idx;
    int step;
    Item(string _word, int _parent_idx, int _step)
        :word(_word)
        ,parent_idx(_parent_idx)
        ,step(_step)
    {}
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        map<string, vector<string>> graph;
        construct_graph(beginWord, wordList, graph);
        BFS(beginWord, endWord, graph, res);
        return res;
    }
    
private:
    bool connect(const string &word1, const string &word2){
        int different = 0;
        for(int i = 0; i < word1.size(); ++i){
            if(word1[i] != word2[i]){
                ++different;
            }
        }
        return different == 1;
    }
    
    void construct_graph(const string &beginWord, vector<string> &wordList, map<string, vector<string>> &graph){
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()){
            wordList.push_back(beginWord);
        }
        for(int i = 0; i < wordList.size(); ++i){
            for(int j = 0; j < wordList.size(); ++j){
                if(connect(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                }
            }
        }
    }
    
    void BFS(const string &beginWord, const string &endWord, map<string, vector<string>> &graph, vector<vector<string>> &res){
        vector<Item> Q;
        map<string, int> visited;
        int min_step = 0;
        Q.push_back(Item(beginWord, -1, 1));
        visited.insert(make_pair(beginWord, 1));
        int front = 0;
        while(front < Q.size()){
            Item word_item = Q[front];
            if(word_item.word != endWord)
                for(auto i : graph[word_item.word]){
                    if(i == endWord){
                        if(min_step == 0 || min_step >= word_item.step + 1){
                            min_step = word_item.step + 1;
                            Q.push_back(Item(i, front, word_item.step + 1));
                        }
                    }else{
                        if(visited.find(i) == visited.end() || visited[i] >= word_item.step+1){
                            Q.push_back(Item(i, front, word_item.step + 1));
                            visited[i] = word_item.step + 1;
                        }
                    }
                }
            ++front;
        }
        vector<string> tmp;
        for(int i = Q.size()-1; i >= 0; --i){
            if(Q[i].word != endWord)
                continue;
            int j = i;
            while(j >= 0){
                tmp.push_back(Q[j].word);
                j = Q[j].parent_idx;
            }
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            tmp.clear();
        }
    }
};

int main()
{
    Solution sol;
    string beginWord("hit");
    string endWord("cog");
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> res = sol.findLadders(beginWord, endWord, wordList);
    for(auto i : res){
        cout << "solve: " << endl;
        for(auto j : i){
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}