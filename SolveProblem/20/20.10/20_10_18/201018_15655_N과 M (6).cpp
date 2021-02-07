#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int arr[8], ans[8];

void solve(int idx, int cnt) {
	if(cnt==m) {
		for(int i=0;i<cnt;i++) cout<<ans[i]<<' ';
		cout<<"\n";
		return;
	}
	if(idx==n) return;
	
	for(int i=idx;i<n;i++) {
		ans[cnt] = arr[i];
		solve(i+1,cnt+1);
	}
}

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++) {
		ans[0] = arr[i];
		solve(i+1,1);
	}
	return 0;
}
