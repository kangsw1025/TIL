#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int ans = 1;

int main() {
	int n, len = 1;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=1;i<n;i++) {
		if(arr[i]>=arr[i-1]) len++;
		else len = 1;
		ans = max(ans,len);
	}
	len = 1;
	for(int i=1;i<n;i++) {
		if(arr[i]<=arr[i-1]) len++;
		else len = 1;
		ans = max(ans,len);
	}
	cout<<ans;
	return 0;
} 
