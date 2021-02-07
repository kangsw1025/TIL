#include<iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long a,b;
	cin>>a>>b;
	long long ans = gcd(a,b);
	for(int i=0;i<ans;i++) cout<<1;
	return 0;
}
