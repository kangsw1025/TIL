#include<iostream>
#include<algorithm>
using namespace std;

int arr[10001];
int tmp[10001];

int main() {
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		tmp[i] = arr[i];
	}
	sort(tmp,tmp+n);
	next_permutation(arr,arr+n);
	
	bool check = true;
	
	for(int i=0;i<n;i++)
		if(tmp[i]!=arr[i]) {
			check=false;
			break;
		}
	
	if(!check) 
		for(int i=0;i<n;i++) cout<<arr[i]<<' ';
	else cout<<-1;
	return 0;
}
