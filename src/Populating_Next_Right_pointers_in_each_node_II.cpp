#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> current,next;
		if(root) current.push(root);
		while(!current.empty()){
			TreeLinkNode *pre = nullptr;
			while(!current.empty()){
				if(current.front()->left) next.push(current.front()->left);
				if(current.front()->right) next.push(current.front()->right);

				if(pre) pre->next = current.front();
				pre = current.front();
				current.pop();
			}
			swap(current,next);
		}
    }
};

int main()
{
	Solution s;
	
	TreeLinkNode *root = new TreeLinkNode(1);

	TreeLinkNode *tln1 = new TreeLinkNode(2);
	TreeLinkNode *tln2 = new TreeLinkNode(3);

	TreeLinkNode *tln3 = new TreeLinkNode(4);
	TreeLinkNode *tln4 = new TreeLinkNode(5);
	TreeLinkNode *tln5 = new TreeLinkNode(6);

	root->left = tln1;root->right = tln2;

	tln1->left = tln3;

	tln2->left = tln4;tln2->right = tln5;

	s.connect(root);
	
	delete root;
	delete tln1;
	delete tln2;
	delete tln3;
	delete tln4;
	delete tln5;

	system("pause");
	return 0;
}