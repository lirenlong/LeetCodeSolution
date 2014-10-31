#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Leaf_info {
	TreeNode *parent;
	bool isRightChild;
	//上下界的索引
	unsigned int upperBound;
	unsigned int lowerBound;

	Leaf_info(TreeNode *p,bool isright,unsigned int lB,unsigned int uB):parent(p), isRightChild(isright), upperBound(uB), lowerBound(lB) {}
	bool isIn(int t) {
		return (t >= lowerBound && t < upperBound);
	}
};

class Solution {
public:
	unsigned int MAX;
	unsigned int MIN;
	int indexInorder(vector<int> &inorder, int value) {
		for(int i = 0 ; i < inorder.size() ; ++i) {
			if(inorder[i] == value)
				return i;
		}
		return -1;
	}
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        vector<Leaf_info*> vecLeaf;
		TreeNode *res = NULL;
		MIN = 0;
		MAX = (unsigned int)(0) - 1;
		for(int i = 0 ; i < preorder.size() ; ++i) {
			TreeNode *tmp = new TreeNode(preorder[i]);
			int curInorderIndex = indexInorder(inorder,preorder[i]);
			if(!res) {
				res = tmp;
				Leaf_info *leaf1 = new Leaf_info(res,false,0,curInorderIndex);
				Leaf_info *leaf2 = new Leaf_info(res,true,curInorderIndex,MAX);
				vecLeaf.push_back(leaf1);
				vecLeaf.push_back(leaf2);
			}
			else {
				for(vector<Leaf_info*>::iterator it = vecLeaf.begin() ; it != vecLeaf.end();) {
					if((*it)->isIn(curInorderIndex)) {
						TreeNode *target = (*it)->parent;
						(*it)->isRightChild?target->right = tmp:target->left = tmp;

						int a = (*it)->lowerBound;
						int b = (*it)->upperBound;

						delete (*it);
						vector<Leaf_info*>::iterator it2 = it;
						vecLeaf.erase(it2);

						if(curInorderIndex != a ) {
							Leaf_info *leaf1 = new Leaf_info(tmp,false,a,curInorderIndex);
							vecLeaf.push_back(leaf1);
						}
						if(curInorderIndex != b ) {
							Leaf_info *leaf2 = new Leaf_info(tmp,true,curInorderIndex,b);
							vecLeaf.push_back(leaf2);
						}
						
						break;
					}
					else {
						 it++;
					}
				}
			}
		}
		for(vector<Leaf_info*>::iterator it = vecLeaf.begin() ; it != vecLeaf.end(); ++it){
			delete (*it);
		}
		vecLeaf.clear();
		return res;
    }
	
	
public:
	//高富帅写法
	TreeNode* buildTreeGFS(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(begin(preorder), end(preorder),begin(inorder), end(inorder));
	}
	template<typename InputIterator>
	TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last,InputIterator in_first, InputIterator in_last) {
		if (pre_first == pre_last) return nullptr;
		if (in_first == in_last) return nullptr;
		auto root = new TreeNode(*pre_first);
		auto inRootPos = find(in_first, in_last, *pre_first);
		auto leftSize = distance(in_first, inRootPos);
		root->left = buildTree(next(pre_first), next(pre_first,
			leftSize + 1), in_first, next(in_first, leftSize));
		root->right = buildTree(next(pre_first, leftSize + 1), pre_last,
			next(inRootPos), in_last);
		return root;
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

	TreeNode*root = s.buildTree(preOrder,inorder);

	system("pause");
	return 0;
}