//
//  main.m
//  test
//
//  Created by rogerLee on 27/10/14.
//  Copyright (c) 2014 rogerLee. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string evalItem(string a,string b,string opera){
        char op = opera[0];
        int res = 0;
        switch(op){
            case '+':res = atoi(a.c_str()) + atoi(b.c_str());break;
            case '-':res = atoi(a.c_str()) - atoi(b.c_str());break;
            case '/':res = atoi(a.c_str()) / atoi(b.c_str());break;
            case '*':res = atoi(a.c_str()) * atoi(b.c_str());break;
        }
        char num[11];
        sprintf(num,"%d",res);
        string str(num);
        return str;
    }
    int evalRPN(vector<string> &tokens) {
        stack<string> stkstr;
        char num[11];
        sprintf(num,"%d",0);
        string ans(num);
        stkstr.push(ans);
        for(int i = 0 ; i < tokens.size() ;  ++i){
            if(tokens[i][tokens[i].size()-1] >= '0' && tokens[i][tokens[i].size()-1] <= '9')
                stkstr.push(tokens[i]);
            else{
                string a = stkstr.top();stkstr.pop();
                string b = stkstr.top();stkstr.pop();
                stkstr.push(evalItem(b,a,tokens[i]));
            }
        }
        return atoi(stkstr.top().c_str());
    }
};

int main(){
    vector<string> vec;
    vec.push_back("2");
    vec.push_back("1");
    vec.push_back("+");
    vec.push_back("3");
    vec.push_back("*");
    Solution s;
    int res = s.evalRPN(vec);
    cout<<res<<endl;
    return 0;
}