#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

bool cmp(int a, int b) {
	return a>b;
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n,cmp);
	
	long long ans = 0;
	for(int i=0;i<n;i++) 
		if((arr[i]-i)>0) ans += arr[i]-i;
	
	cout<<ans;
	return 0;
}
