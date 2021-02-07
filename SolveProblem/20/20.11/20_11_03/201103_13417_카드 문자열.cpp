#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		string word="";
		for(int i=0;i<n;i++) {
			char c;
			cin>>c;
			if(i==0) word = c;
			else {
				if(c<=word[0]) word = c + word;
				else word += c;
			}
		}
		cout<<word<<"\n";
	}
	return 0;
}
