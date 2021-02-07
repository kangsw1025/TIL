#include<iostream>
using namespace std;

int arr[51];

int main() {
	int n,score,p;
	int ans = 0;
	cin>>n>>score>>p;
	for(int i=0;i<n;i++) cin>>arr[i];
	int idx = 1;
	if(n==p && arr[n-1]>=score) idx = -1;
	else {
		for(int i=0;i<n;i++)
			if(arr[i]>score) idx++;
	}
	cout<<idx;
	return 0;
}
