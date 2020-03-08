
#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
#include <set>

void preorder(TreeNode* node,
			  TreeNode *search,
		   	  std::vector<TreeNode*> &path,
		   	  std::vector<TreeNode*> &result,
			  int finish){
				  if(finish || !node){
					  return;
				  }
				  path.push_back(node);
				  if(node == search){
					  result = path;
					  finish = 1;
				  }
				preorder(node->left, search, path, result, finish);
				preorder(node->right, search, path, result, finish);
				path.pop_back();
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		std::vector<TreeNode*> vec_p;
		std::vector<TreeNode*> vec_q;
		std::vector<TreeNode*> path;
		preorder(root, p, path, vec_p, 0);
		path.clear();
		preorder(root, q, path, vec_q, 0);
		int p_len = 0;
		int q_len = 0;
		TreeNode* result = NULL;
		while(p_len < vec_p.size() && q_len < vec_q.size()){
			if(vec_q[q_len] == vec_p[p_len]){
				if(q_len+1 == vec_q.size() || p_len+1 == vec_p.size()){
					result = vec_p[p_len];
					break;
				}
				if(vec_p[p_len+1] != vec_q[q_len+1]){
					result = vec_q[q_len];
					break;
				}
			}
			++q_len;
			++p_len;
		}
		return result;
    }
};

int main(){
	TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;
	
	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &b, &y);
	printf("lowestCommonAncestor = %d\n", result->val);
	
	return 0;
}


