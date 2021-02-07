#include<iostream>
#include<algorithm>
using namespace std;
 
int arr[1001];

int main() {
	int n,l;
	cin>>n>>l;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++) if(arr[i]<=l) l++;
	cout<<l;
	return 0;
} 
