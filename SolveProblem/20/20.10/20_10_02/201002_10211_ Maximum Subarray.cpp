#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[1001];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, ans=-2e9;
		cin>>n;
		for(int i=1;i<=n;i++) {
			int num;
			cin>>num;
			arr[i] = arr[i-1] + num;
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				ans = max(ans,arr[j]-arr[i-1]);
		cout<<ans<<"\n";
	}
	return 0;
}
