#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int> &num) {
		int left = 0, right =  num.size()-1;
		while (left < right) {
			while (left < right && num[left] == num[right])
				right--;
			if (num[left] < num[right])
				return num[left];
			int mid = (left+right)>>1;
			if (num[mid] >= num[left]) {
				if (num[mid+1] < num[left])
					return num[mid+1];
				left = mid+1;
			} else {
				right = mid;
			}
		}
		return num[right];
	}
};


int main()
{
	Solution s;

	vector<int> data;
	//data.push_back(4);
	//data.push_back(5);
	data.push_back(10);
	data.push_back(0);
	data.push_back(10);
	data.push_back(10);
	data.push_back(10);
	cout<<s.findMin(data)<<endl;
	system("pause");
	return 0;
}