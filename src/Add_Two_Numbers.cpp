#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ans = NULL;
		if(l1 ==NULL || l2 ==NULL)
			return ans;
		ans = new ListNode((l1->val + l2->val)%10);
		
		bool isCarry = (l1->val + l2->val)/10 == 0 ? false : true;

		ListNode *tmp = NULL;
		ListNode *pre = ans;
		
		if(l1) l1 = l1->next;
		if(l2) l2 = l2->next;

		while(l1 || l2) {
			if(l1 && l2) {
				char c = (l1->val + l2->val + (isCarry?1:0));
				tmp = new ListNode(c%10);
				isCarry = c/10 == 0 ? false : true;
				pre->next = tmp;
				pre = tmp;
			}
			else if(l1) {
				char c = (l1->val + (isCarry?1:0));
				tmp = new ListNode(c%10);
				isCarry = c/10 == 0 ? false : true;
				pre->next = tmp;
				pre = tmp;
			}
			else {
				char c = (l2->val + (isCarry?1:0));
				tmp = new ListNode(c%10);
				isCarry = c/10 == 0 ? false : true;
				pre->next = tmp;
				pre = tmp;
			}

			if(l1) l1 = l1->next;
			if(l2) l2 = l2->next;
		}
		if(isCarry)
			pre->next = new ListNode(1);
		return ans;
    }
	

public:
	//高富帅写法
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1); // 头节点
		int carry = 0;
		ListNode *prev = &dummy;
		for (ListNode *pa = l1, *pb = l2;
		pa != nullptr || pb != nullptr;
		pa = pa == nullptr ? nullptr : pa->next,
		pb = pb == nullptr ? nullptr : pb->next,
		prev = prev->next) {
		const int ai = pa == nullptr ? 0 : pa->val;
		const int bi = pb == nullptr ? 0 : pb->val;
		const int value = (ai + bi + carry) % 10;
		carry = (ai + bi + carry) / 10;
		prev->next = new ListNode(value); // 尾插法
		}
		if (carry > 0)
		prev->next = new ListNode(carry);
		return dummy.next;
	}
};


int main(){
	Solution s;

	ListNode *a1 = &ListNode(2);
	ListNode *a2 = &ListNode(4);
	ListNode *a3 = &ListNode(3);
	ListNode *a4 = &ListNode(5);
	ListNode *a5 = &ListNode(6);
	//ListNode *a6 = &ListNode(6);

	a1->next = a2;
	a2->next = a3;
	
	a4->next = a5;
	//a5->next = a6;

	ListNode *res = s.addTwoNumbers(a1,a4);
	ListNode *tmp = res;
	while(tmp){
		cout<<tmp->val<<endl;
		res = tmp;
		tmp = tmp->next;
		delete res;
	}

	
	system("pause");
	return 0;
}