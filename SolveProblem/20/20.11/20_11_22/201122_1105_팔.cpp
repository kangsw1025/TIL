#include<iostream>
using namespace std;

int main() {
	int a,b,c=1000000000,ans = 0;
	cin>>a>>b;
	while(c) {
		if(a/c%10 != b/c%10) break;
		else if(a/c%10 == b/c%10 && a/c%10 == 8 && b/c%10==8) ans++;
		c/=10;
	}
	cout<<ans;
	return 0;
} 
