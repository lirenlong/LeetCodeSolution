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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
		queue<TreeNode*> current,next;
		bool isReverse = false;
		if(root) current.push(root);
		while(!current.empty()){
			vector<int> resItem;
			while(!current.empty()){
				TreeNode* tmp = current.front();current.pop();
				resItem.push_back(tmp->val);
				if(tmp->left) next.push(tmp->left);
				if(tmp->right) next.push(tmp->right);
			}
			if(isReverse)
				reverse(resItem.begin(),resItem.end());
			isReverse = isReverse?false:true;
			res.push_back(resItem);
			swap(next,current);
		}
		return res;
    }
};

int main()
{
	Solution s;
	TreeNode *tn1 = &TreeNode(1);
	tn1->left = &TreeNode(2);
	tn1->right = &TreeNode(3);

	tn1->right->left = &TreeNode(4);
	tn1->right->right = &TreeNode(5);

	vector<vector<int>> res = s.zigzagLevelOrder(tn1);
	res.size();
	system("pause");
	return 0;
}