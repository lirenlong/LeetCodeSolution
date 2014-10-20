#include <stdio.h>
#include <vector>
#include <numeric>
#include <functional>
#include <queue>
using namespace std;

void printTwoDimention(vector<vector<int>>&);

class Solution
{
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		for(int i = 0 ;i < n/2;++i)
		{
			for(int j = 0 ;j < m/2;++j)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[m-j-1][i];
				matrix[m-j-1][i] = matrix[n-i-1][m-j-1];
				matrix[n-i-1][m-j-1] = matrix[j][n-i-1];
				matrix[j][n-i-1] = tmp;
				//printTwoDimention(matrix);
			}
		}
	}
};

void printTwoDimention(vector<vector<int>> &v)
{
	int n = v.size();
	int m = v[0].size();
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < m ;++j)
			printf("%d ",v[i][j]);
		printf("\n");
	}
	printf("===============\n");
}

//https://oj.leetcode.com/problems/rotate-image/
int main()
{
	Solution s;
	vector<vector<int>> data;
	int datar = 0;
	for(int i = 0 ; i < 3 ; ++i)
	{
		vector<int> tmp;
		for(int j = 0 ; j < 3 ;++j)
			tmp.push_back(datar++);
		data.push_back(tmp);
	}
	printTwoDimention(data);
	s.rotate(data);
	printTwoDimention(data);
	return 0;
}