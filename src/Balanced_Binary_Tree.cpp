#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	map<TreeNode*,unsigned int> heightMap;
	unsigned int height(TreeNode *node){
		if(node == NULL)
			return 0;

		if(heightMap.find(node) != heightMap.end())
			return heightMap[node];

		if(node->left == NULL && node->right == NULL){
			heightMap[node] = 1;
			return 1;
		}

		unsigned int a = height(node->left);
		unsigned int b = height(node->right);
		heightMap[node] = (a>=b ? a:b) + 1;
		return heightMap[node];
	}
    bool isBalanced(TreeNode *root) {
		if(root == NULL) return true;

		if(root->left){
			if(!isBalanced(root->left)) return false;
		}

        unsigned int l = height(root->left);
		unsigned int r = height(root->right);
		if(abs((int)(l-r)) >= 2)
			return false;
		
		if(root->right){
			if(!isBalanced(root->right)) return false;
		}
		return true;
    }
};


int main(){
	Solution s;

	TreeNode *r = &TreeNode(1);
	TreeNode *rl = &TreeNode(2);
	TreeNode *rr = &TreeNode(6);
	r->left = rl;
	r->right = rr;

	TreeNode *ll = &TreeNode(4);
	rl->left = ll;
	rl->right = &TreeNode(5);

	ll->left = &TreeNode(7);
	ll->right = &TreeNode(8);

	cout<<s.isBalanced(r)<<endl;

	system("pause");
	return 0;
}