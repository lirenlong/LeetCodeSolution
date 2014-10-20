#include <stdio.h>
#include <vector>
#include <numeric>
#include <functional>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL)
			return node;

		vector<UndirectedGraphNode *> vecCache;
		queue<UndirectedGraphNode *> queNextTask;

		UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
		UndirectedGraphNode *cursor = head;
		UndirectedGraphNode *target = node;
		
		vecCache.push_back(cursor);
		queNextTask.push(cursor);
		queNextTask.push(target);
		while(!queNextTask.empty())
		{
			cursor = queNextTask.front();
			queNextTask.pop();
			target = queNextTask.front();
			queNextTask.pop();

			//add the neighbors
			int j;
			for(j = 0; j < target->neighbors.size(); ++j)
			{
				//find it in the cache
				int i;
				for(i = 0; i < vecCache.size(); ++i)
				{
					if(vecCache[i]->label == target->neighbors[j]->label)
						break;
				}
				
				UndirectedGraphNode *tmp = NULL;
				if(i == vecCache.size())
				{
					tmp = new UndirectedGraphNode(target->neighbors[j]->label);
					vecCache.push_back(tmp);
					queNextTask.push(tmp);
					queNextTask.push(target->neighbors[j]);
				}
				else
				{
					tmp = vecCache[i];
				}
				cursor->neighbors.push_back(tmp);
			}
		}
		return head;
	}
};

//https://oj.leetcode.com/problems/clone-graph/
int main()
{
	Solution s;
	
	UndirectedGraphNode *head = new UndirectedGraphNode(0);
	UndirectedGraphNode *p1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *p2 = new UndirectedGraphNode(2);
	head->neighbors.push_back(p1);
	head->neighbors.push_back(p2);

	p1->neighbors.push_back(p2);
	p2->neighbors.push_back(p2);

	UndirectedGraphNode *p = s.cloneGraph(head);
	printf("%d",p->label);
	return 0;
}