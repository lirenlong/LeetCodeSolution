#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> index;
    void recoverTree(TreeNode *root) {
		inorder(root);
		TreeNode* a,*b;a=b=nullptr;
		bool isSecond = false;
		int j = -1;
		for(int i = 1;i < index.size(); ++i){
			if(index[i]->val < index[i-1]->val){
				if(isSecond){
					b = index[i];
				}
				else{
					a = index[i-1];
					j = i;
					isSecond = true;
				}
			}
		}
		if(b == nullptr)
			b = index[j];

		//value swap
		swap(a->val,b->val);

		////memory position swap
		//if(a->left == b){
		//	a->left = a;
		//}
		//else if(a->right == b){
		//	a->right = a;
		//}
		//else if(b->left == a){
		//	b->left = b;
		//}
		//else if(b->right == a){
		//	b->right = b;
		//}
		//swap(a->left,b->left);
		//swap(a->right,b->right);
		//bool isAleft,isBleft;
		//TreeNode *ap = parent(a,isAleft);
		//TreeNode *bp = parent(b,isBleft);
		//if(ap&& ap != b) {
		//	isAleft?ap->left = a:ap->right = a;
		//}
		//if(bp && bp != a) {
		//	isBleft?bp->left = b:bp->right = b;
		//}
    }
	void inorder(TreeNode *node){
		if(node==nullptr) return;

		inorder(node->left);
		index.push_back(node);
		inorder(node->right);
	}

	TreeNode* parent(TreeNode *node,bool &isLeft){
		for(int i = 0 ;i < index.size() ; ++i) {
			if(index[i]->left == node) {isLeft = true;return index[i];}
			if(index[i]->right == node) {isLeft = false;return index[i];}
		}
		return NULL;
	}
};

int main()
{
	Solution s;
	/*TreeNode *tn1 = new TreeNode(10);
	TreeNode *root = new TreeNode(20);
	tn1->left = root;
	tn1->right = new TreeNode(40);

	tn1->right->left = new TreeNode(30);
	tn1->right->right = new TreeNode(50);*/

	TreeNode *tn1 = new TreeNode(0);
	TreeNode *tn2 = new TreeNode(1);
	tn1->left = tn2;

	s.recoverTree(tn1);
	
	system("pause");
	return 0;
}