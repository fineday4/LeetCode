
#include <stdio.h>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <string>
#include <vector>
using namespace std;

void BST_insert(TreeNode *node, TreeNode *insert_node){
	if(!node||!insert_node)
		return;
	if(node->val > insert_node->val){
		if(node->left){
			BST_insert(node->left, insert_node);
		}else{
			node->left = insert_node;
		}
	}else{
		if(node->right){
			BST_insert(node->right, insert_node);
		}else{
			node->right = insert_node;
		}
	}
}

void change_int_to_string(int val, std::string &str_val){
	string tmp;
	while(val){
		tmp.push_back(val%10+'0');
		val = val/10;
	}
	for(int i = tmp.size()-1; i >= 0; --i){
		str_val.push_back(tmp[i]);
	}
	str_val.push_back('#');
}

void BST_preorder(TreeNode *node, std::string &data){
	if(!node)
		return ;
	int val = node->val;
	change_int_to_string(val, data);
	BST_preorder(node->left, data);
	BST_preorder(node->right, data);
}

class Codec {
public:
    std::string serialize(TreeNode* root) {
    	std::string data;
        BST_preorder(root, data);
        return data;
    }
    TreeNode *deserialize(std::string data) {
		vector<TreeNode*> tree_vec;
		int val = 0;
		for(int i = 0; i < data.size(); ++i){
			if(data[i] == '#'){
				tree_vec.push_back(new TreeNode(val));
				val = 0;
			}else{
				val = 10*val + (data[i] - '0');
			}
		}
		for(int i = 1; i < tree_vec.size(); ++i){
			BST_insert(tree_vec[0], tree_vec[i]);
		}
		return tree_vec[0];
    }
};

void preorder_print(TreeNode *node,int layer){
	if(!node)
		return;
	printf("node-> %d-------layer: %d\n", node->val, layer);
	preorder_print(node->left, layer+1);
	preorder_print(node->right, layer+1);
}

int main(){
	TreeNode a(8);
	TreeNode b(3);
	TreeNode c(10);
	TreeNode d(1);
	TreeNode e(6);
	TreeNode f(15);	
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;	
	Codec solve;	
	std::string data = solve.serialize(&a);
	printf("%s\n", data.c_str());
	TreeNode *root = solve.deserialize(data);
	preorder_print(root, 0);	
	return 0;
}
