#include<iostream>
#include<string>
using namespace std;

int main() {
	
	string w;
	cin>>w;
	int sum = 0;
	int check;
	for(int i=0;i<w.length();i++) {
		if(w[i]!='*') {
			if(i%2) sum += (w[i]-'0')*3;
			else sum += w[i]-'0';
		}
		else {
			if(i%2) check = 3;
			else check = 1;
		}
	}
	
	for(int i=0;i<=9;i++) {
		if((sum+i*check)%10==0) {
			cout<<i;
			break;
		}
	}
	return 0;
}
