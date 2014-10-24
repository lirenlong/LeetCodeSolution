#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		char *delim = " ";
		char *p = strtok((char*)s.c_str(), delim);

		stack<string> stackStr;
		while(p){
			//cout<<p<<endl;
			stackStr.push(string(p));
			p = strtok(NULL,delim);
		}
		s.clear();
		while(!stackStr.empty())
		{
			s.append(stackStr.top());
			stackStr.pop();
			if(!stackStr.empty())
				s.append(" ");
		}
	}
};


int main(){
	Solution s;

	string str("");// I am a person 
	s.reverseWords(str);
	cout<<"======"<<endl;
	cout<<"1"<<str<<"1"<<endl;
	system("pause");
	return 0;
}