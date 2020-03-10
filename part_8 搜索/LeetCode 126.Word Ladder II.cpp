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
        // for(auto i : graph){
        //     cout << "word: " << i.first << endl;
        //     for(auto j : i.second){
        //         cout << " " << j ;
        //     }
        //     cout << endl;
        // }
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
        int front = 0;
        int min_step = 0;
        map<string, int> visited;
        Q.push_back(Item(beginWord, -1, 1));
        visited.insert(make_pair(beginWord, 1));
        while(front < Q.size()){
            Item ite = Q[front];
            if(ite.word != endWord) 
                for(auto i : graph[ite.word]){
                    cout << "ite.word: " << ite.word << "--->i: " << i << endl;
                    if(min_step == 0 && i == endWord){
                        min_step = ite.step+1; 
                        visited[i] = ite.step + 1;
                        Q.push_back(Item(i, front, ite.step + 1));
                        // ++front;                 
                        break;
                    }else if(i == endWord && min_step < ite.step + 1){
                        continue;
                    }
                    if(visited.find(i) == visited.end()|| visited[i] >= ite.step + 1){
                        visited[i] = ite.step + 1;
                        Q.push_back(Item(i, front, ite.step + 1));
                    }
                }
            ++front;
        }
        cout << "size of Q: " << Q.size() << endl;
        for(int i = Q.size()-1; i > 0; --i){
            cout << "Q.word: " << Q[i].word << endl;
            if(Q[i].word != endWord)
                continue;
            vector<string> tmp;
            for(int j = i; j >= 0;){
                tmp.push_back(Q[j].word);
                j = Q[j].parent_idx;
                cout << "j: " << j << endl;
            }
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
    }
};

int main()
{
    Solution sol;
    string beginWord("teach");
    string endWord("place");
    vector<string> wordList{"peale","wilts","place","fetch","purer","pooch","peace","poach","berra","teach","rheum","peach"};
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