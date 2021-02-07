#include<iostream>
#include<algorithm>
using namespace std;

int arr[101][101];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int x,y;
		cin>>x>>y;
		for(int i=y+1;i<=y+10;i++)
			for(int j=x+1;j<=x+10;j++)
				arr[i][j] = 1;
	}
	
	int rst = 0;
	for(int i=1;i<101;i++)
		for(int j=1;j<101;j++)
			if(arr[i][j]) rst++;
	cout<<rst;
	return 0;
}
