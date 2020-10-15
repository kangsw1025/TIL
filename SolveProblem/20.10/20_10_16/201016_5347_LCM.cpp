#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	int ans;
	bool check = false;
	for(int i=2;i<=min(a,b);i++) {
		if(a%i==0 && b%i==0) {
			ans = i;
			check = true;
			break;
		}
	}
	if(check) return ans * gcd(a/ans,b/ans);
	return a*b;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		int a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<"\n";
	}
	return 0;
}
