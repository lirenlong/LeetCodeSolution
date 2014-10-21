#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//顺序遍历O(n)
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
	
	//二分法 O(logn)
	int findMin2(vector<int> &num) {
        int l = 0, r =  num.size()-1;
        if (num[l] < num[r])
            return num[l];
        while (l < r) {
            int mid = (l+r)>>1;
            if (num[mid] >= num[l]) {
                if (num[mid+1] < num[l])
                    return num[mid+1];
                
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return num[r];
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