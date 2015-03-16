//
//  Number_of_1bits.cpp
//  LeetCode
//
//  Created by rogerLee on 16/3/15.
//
//
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (((n >> i ) & 1) == 1) {
                ++res;
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    int res = s.hammingWeight(n);
    cout<<res<<endl;
    return 0;
}