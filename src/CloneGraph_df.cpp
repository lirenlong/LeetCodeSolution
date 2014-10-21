#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	map<UndirectedGraphNode *,UndirectedGraphNode *> Map;
	void cloneItem(UndirectedGraphNode *head,UndirectedGraphNode * cur)
	{
		//cout<<cur->label<<endl;
		int n = cur->neighbors.size();
		for(int i = 0 ; i < n ; ++i)
		{
			if(Map.find(cur->neighbors[i]) == Map.end())
			{
				UndirectedGraphNode *tmp = new UndirectedGraphNode(cur->neighbors[i]->label);
				Map[(UndirectedGraphNode *)cur->neighbors[i]] = tmp;
				head->neighbors.push_back(tmp);
				cloneItem(tmp,(UndirectedGraphNode *)cur->neighbors[i]);
			}
			else
			{
				head->neighbors.push_back(Map[(UndirectedGraphNode *)cur->neighbors[i]]);
			}
		}
	}
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL)
			return node;
		UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
		Map[node] = head;
		cloneItem(head,node);
		return head;
	}
};

//https://oj.leetcode.com/problems/clone-graph/
int main()
{
	Solution s;

	//0,1,2#1,2#2,2
	UndirectedGraphNode *head = new UndirectedGraphNode(0);
	UndirectedGraphNode *p1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *p2 = new UndirectedGraphNode(2);
	head->neighbors.push_back(p1);
	head->neighbors.push_back(p2);

	p1->neighbors.push_back(p2);
	p2->neighbors.push_back(p2);

	UndirectedGraphNode *p = s.cloneGraph(head);
	system("pause");
	return 0;
}