#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 1)
			return A[0];
		int *dp_max = new int[n];
		int *dp_min = new int[n];
		dp_max[0] = dp_min[0] = A[0];
		
		int res = A[0];
		
		for(int i = 1 ; i < n ; ++i)
		{
			dp_max[i] = max(A[i],dp_max[i-1]*A[i]);
			dp_min[i] = min(A[i],dp_min[i-1]*A[i]);
			dp_max[i] = max(dp_max[i],dp_min[i-1]*A[i]);
			dp_min[i] = min(dp_min[i],dp_max[i-1]*A[i]);
			res = max(res,dp_max[i]);
		}
		delete []dp_max;
		delete []dp_min;
		return res;
    }
};

int main()
{
	Solution s;
	int a[5] = {-1,2,3,-6};
	cout<<s.maxProduct(a,5)<<endl;
	return 0;
}