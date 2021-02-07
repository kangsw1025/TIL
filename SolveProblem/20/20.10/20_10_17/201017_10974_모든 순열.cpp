#include<iostream>
#include<algorithm>
using namespace std;

int arr[8];

int fac(int n) {
	int ans = 1;
	for(int i=n;i>=1;i--) ans *= i;
	return ans;
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++) arr[i] = i +1;
	for(int i=0;i<n;i++) cout<<arr[i]<<' ';
	cout<<"\n"; 
	int cnt = fac(n);
	for(int i=0;i<cnt-1;i++) {
		next_permutation(arr,arr+n);
		for(int j=0;j<n;j++) cout<<arr[j]<<' ';
		cout<<"\n";
	}
	return 0;
}
