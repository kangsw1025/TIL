#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(char a, char b) {
	return a>b;
}

int main() {
	string n;
	cin>>n;
	
	long long sum = 0;
	bool find = false;
	
	for(int i=0;i<n.length();i++) {
		sum += (n[i]-'0');
		if(!(n[i]-'0')) find = true;
	}
	
	if(sum%3 || !find) cout<<-1;
	else {
		sort(n.begin(),n.end(),cmp);
		cout<<n;
	}
	return 0;
}
