#include<iostream>
using namespace std;

int cnt(int n) {
	int num = 1;
	while(--n) num = num*2 + 1;
	return num;
}

void solve(int n, int from, int by, int to) {
	if(n==1) cout<<from<<' '<<to<<"\n";
	else {
		solve(n-1,from,to,by);
		cout<<from<<' '<<to<<"\n";
		solve(n-1,by,from,to);
	}
}

int main() {
	int n;
	cin>>n;
	cout<<cnt(n)<<"\n";
	solve(n,1,2,3);
	return 0;
}
