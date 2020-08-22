#include<iostream>
using namespace std;

int arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int num;
		cin>>num;
		
		for(int j=1;j<=n;j++) {
			if(num==0 && arr[j]==0) {
				arr[j] = i;
				break;
			}
			else if(arr[j]==0) num--;
		}
	}
	
	for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
	return 0;
}
