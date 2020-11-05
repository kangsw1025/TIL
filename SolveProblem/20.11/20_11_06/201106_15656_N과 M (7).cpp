#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int arr[8], ans[8];

void solve(int cnt) {
	if(cnt==m) {
		for(int i=0;i<m;i++) cout<<ans[i]<<' ';
		cout<<"\n";
		return;
	}
	
	for(int i=0;i<n;i++) {
		ans[cnt] = arr[i];
		solve(cnt+1);
	}
}

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++) {
		ans[0] = arr[i];
		solve(1);
	}
	return 0;
}
