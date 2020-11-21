#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define INF 987654231
#define MAX 51

int n;
int arr[MAX][MAX];

void solve() {
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) {
				if(i==j || j==k || k==i) continue;
				else if(arr[i][j]>arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) {
		string tmp;
		cin>>tmp;
		
		for(int j=0;j<tmp.length();j++) {
			if(i==j) arr[i][j] = 0;
			else arr[i][j] = tmp[j]=='Y'?1:INF;
		}
	}
	
	solve();
	
	int rst = 0;
	for(int i=0;i<n;i++) {
		int cnt = 0;
		
		for(int j=0;j<n;j++) {
			if(i==j) continue;
			else if(arr[i][j]<=2) cnt++;
		}
		rst = max(rst,cnt);
	}
	cout<<rst;
	return 0;
}
