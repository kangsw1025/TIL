#include<iostream>
#include<algorithm>
using namespace std;

int arr[9];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,sum,ans=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	do {
		sum = 0;
		for(int i=0;i<n-1;i++)
			sum += abs(arr[i]-arr[i+1]);
		ans = max(ans,sum);
	} while(next_permutation(arr,arr+n));
	cout<<ans;
	return 0;
} 
