#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int> &num) {
		if(num[0] < num[num.size()-1]) return num[0];
		int pre = num[0];
		int i;
		for(i = 1; i < num.size(); ++i)
		{
			if(num[i] < pre) {pre = num[i];break;}
			pre = num[i];
		}
		/*if(i == num.size())
		pre = num[0];*/
		return pre;
	}
};


int main()
{
	Solution s;

	vector<int> data;
	data.push_back(4);
	data.push_back(5);
	data.push_back(6);
	data.push_back(7);
	data.push_back(0);
	data.push_back(1);
	data.push_back(2);
	cout<<s.findMin(data)<<endl;
	system("pause");
	return 0;
}