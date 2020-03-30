#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRIE_MAX_CHAR_NUM 26

struct TrieNode{
	TrieNode *child[TRIE_MAX_CHAR_NUM];
	bool is_end;
	TrieNode():is_end(false){
		for(int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
			child[i] = NULL;
	}
};

class TrieTree{
	private:
		TrieNode root;
		vector<TrieNode*> node_vec;
		TrieNode* new_Node(){
			TrieNode* ret = new TrieNode();
			node_vec.push_back(ret);
			return ret;
		}

	public:
		TrieTree(){}

		~TrieTree(){
			for(int i = 0; i < node_vec.size(); ++i)
				delete node_vec[i];
		}

		void insert(const string word){
			TrieNode *tmp = &root;
			for(int i = 0; i < word.size(); ++i){
				int pos = word[i] - 'a';
				if(!tmp->child[pos]){
					tmp->child[pos] = new_Node();
				}
				tmp = tmp->child[pos];
			}
			tmp->is_end = true;
		}

		bool search(const string word){
			TrieNode *tmp = &root;
			for(int i = 0; i < word.size(); ++i){
				int pos = word[i] - 'a';
				if(!tmp->child[pos]){
					return false;
				}
				tmp = tmp->child[pos];
			}
			return tmp->is_end;
		}
		
		bool startsWith(const string pre){
			TrieNode* tmp = &root;
			for(int i = 0; i < pre.size(); ++i){
				int pos = pre[i] - 'a';
				if(!tmp->child[pos])
					return false;
				tmp = tmp->child[pos];
			}
			return true;
		}

		void preorder_trie(TrieNode *node){
			if(node->is_end){
				return;
			}
			for(int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
				if(node->child[i]){
					char ch = 'a' + i;
					cout << "-- " << ch << endl;
					preorder_trie(node->child[i]);
				}
			}
		}
		
		TrieNode* getRoot(){
			return &root;
		}

		void get_all_word_from_trie(vector<string> &OUT_strings, string &IN_word, TrieNode* tmp){
			if(!tmp){
				return ;
			}
			if(tmp->is_end)
				OUT_strings.push_back(IN_word);
				
			for(int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
				if(tmp->child[i]){
					IN_word.push_back('a' + i);
					get_all_word_from_trie(OUT_strings, IN_word, tmp->child[i]);
					IN_word.erase(IN_word.size()-1,1);
				}
			}

		}
};

void preorder_trie(TrieNode *node, int layer){
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
		if (node->child[i]){
			for (int j = 0; j < layer; j++){
				printf("---");
			}
			printf("%c", i + 'a');
			if (node->child[i]->is_end){
				printf("(end)");
			}
			printf("\n");
			preorder_trie(node->child[i], layer + 1);
		}
	}
}

void get_all_word_from_trie(TrieNode *node, std::string &word,
				   std::vector<std::string> &word_list){
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++){
		if (node->child[i]){
			word.push_back(i + 'a');
			if (node->child[i]->is_end){
				word_list.push_back(word);
			}
			get_all_word_from_trie(node->child[i], word, word_list);
			word.erase(word.length()-1, 1);
		}
	}
}

int main(){
	TrieTree trie_tree;
	trie_tree.insert("abcd");
	trie_tree.insert("abc");
	trie_tree.insert("abd");
	trie_tree.insert("b");
	trie_tree.insert("bcd");
	trie_tree.insert("efg");
	printf("preorder_trie:\n");
	preorder_trie(trie_tree.getRoot(), 0);
	printf("\n");	
	std::vector<std::string> word_list;
	std::string word;
	printf("All words:\n");
	//get_all_word_from_trie(trie_tree.getRoot(), word, word_list);
	trie_tree.get_all_word_from_trie(word_list, word, trie_tree.getRoot());
	cout << "get_all_word_from_trie" << endl;
	for (int i = 0; i < word_list.size(); i++){
		printf("%s\n", word_list[i].c_str());
	}
	cout << "------------------" << endl;
	printf("\n");
	printf("Search:\n");
	printf("abc : %d\n", trie_tree.search("abc"));
	printf("abcd : %d\n", trie_tree.search("abcd"));
	printf("bc : %d\n", trie_tree.search("bc"));
	printf("b : %d\n", trie_tree.search("b"));
	printf("\n");
	printf("ab : %d\n", trie_tree.startsWith("ab"));
	printf("abc : %d\n", trie_tree.startsWith("abc"));
	printf("bc : %d\n", trie_tree.startsWith("bc"));
	printf("fg : %d\n", trie_tree.startsWith("fg"));
	return 0;
}
