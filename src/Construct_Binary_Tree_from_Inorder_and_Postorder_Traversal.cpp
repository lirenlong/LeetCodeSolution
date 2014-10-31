#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder.begin(), inorder.end(), postorder.begin() ,postorder.end());
	}

	TreeNode* buildTree(vector<int>::iterator inorder_begin,
						 vector<int>::iterator inorder_end,
						 vector<int>::iterator postorder_begin,
						 vector<int>::iterator postorder_end){
		if(inorder_end == inorder_begin) return nullptr;
		if(postorder_end == postorder_begin) return nullptr;

		int cur = *prev(postorder_end);
		TreeNode *tnCur = new TreeNode(cur);

		vector<int> initr = find(inorder_begin, inorder_end, cur);
		int dis = distance(inorder_begin,initr);

		tnCur->left = buildTree(inorder_begin, inorder_begin + dis, postorder_begin, postorder_begin + dis);
		tnCur->right = buildTree(initr + 1, inorder_end, postorder_begin + dis, postorder_end - 1);

		return tnCur;
	}
};


int main()
{
	Solution s;
	
	vector<int> preOrder;
	preOrder.push_back(6);
	preOrder.push_back(3);
	preOrder.push_back(1);
	preOrder.push_back(2);
	preOrder.push_back(5);
	preOrder.push_back(4);
	preOrder.push_back(8);
	preOrder.push_back(7);
	preOrder.push_back(10);
	preOrder.push_back(9);
	preOrder.push_back(11);

	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	inorder.push_back(5);
	inorder.push_back(6);
	inorder.push_back(7);
	inorder.push_back(8);
	inorder.push_back(9);
	inorder.push_back(10);
	inorder.push_back(11);

	vector<int> postorder;
	postorder.push_back(2);
	postorder.push_back(1);
	postorder.push_back(4);
	postorder.push_back(5);
	postorder.push_back(3);
	postorder.push_back(7);
	postorder.push_back(9);
	postorder.push_back(11);
	postorder.push_back(10);
	postorder.push_back(8);
	postorder.push_back(6);

	//TreeNode*root = s.buildTree(preOrder,inorder);
	TreeNode*root = s.buildTree(inorder,postorder);

	system("pause");
	return 0;
}

i like it