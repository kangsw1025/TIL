#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string word;
	int zero = 0, one = 0;
	
	cin>>word;
	
	if(word[0]=='0') zero++;
	else one++;
	
	for(int i=1;i<word.length();i++) 
		if(word[i]!=word[i-1]) {
			if(word[i]=='0') zero++;
			else one++;
		}
	cout<<min(zero,one);
	return 0;
}
