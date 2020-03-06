#include <stdio.h>

#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
		std::vector<int> views;
		std::queue<TreeNode*> Q;
		if(!root){
			return views;
		}
		Q.push(root);
		Q.push(NULL);
		int layer_view = -1;
		while(Q.size() > 1){
			TreeNode* item = Q.front();
			Q.pop();
			if(item == NULL){
				views.push_back(layer_view);
				layer_view = -1;
				Q.push(NULL);
			}else{
				layer_view = item->val;
				if(item->left)
					Q.push(item->left);
				if(item->right)
					Q.push(item->right);
			}
		}
		views.push_back(layer_view);
		return views;
    }
};

int main(){
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	Solution solve;
	std::vector<int> result = solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]\n", result[i]);	
	}
	return 0;
}
