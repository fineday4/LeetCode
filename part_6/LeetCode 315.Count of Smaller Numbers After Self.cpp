#include <stdio.h>

#include <vector>
struct BSTNode {
	int val;
	int count;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int x) : val(x), left(NULL), right(NULL), count(0) {}
};

void BST_insert(BSTNode *node, BSTNode *insert_node, int &count_small){
	if(!node || !insert_node)
		return;
	if(node->val <= insert_node->val){
		count_small += node->count + 1;
		if(node->right){
			BST_insert(node->right, insert_node, count_small);
		}else{
			node->right = insert_node;
		}
	}else{
		++(node->count);
		if(node->left){
			BST_insert(node->left, insert_node, count_small);
		}else{
			node->left = insert_node;
		}
	}
}

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
		std::vector<int> res(nums.size(), 0);
		std::vector<BSTNode*> vec_tree;
		for(int i = nums.size()-1; i >= 0; --i){
			vec_tree.push_back(new BSTNode(nums[i]));
		}
		for(int i = 1; i < vec_tree.size(); ++i){
			int tmp = 0;
			BST_insert(vec_tree[0], vec_tree[i], tmp);
			res[vec_tree.size()-i-1] = tmp;
		}
		return res;
    }
};

int main(){
	int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]", result[i]);
	}
	printf("\n");
	return 0;
}
