#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring> 
using namespace std;

int x,y;
int arr[51][51];
bool check[51][51];
int n_x[4] = {0,-1,0,1};
int n_y[4] = {-1,0,1,0};

int solve(int w, int h) {
	check[w][h]= true;
	queue<pair<int,int> >q;
	q.push(make_pair(w,h));
	int cnt = 1;
	while(!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		
		int bit = 1;
		for(int k =0;k<4;k++) {
			if(!(arr[i][j]&bit)) {
				int nx = i+n_x[k];
				int ny = j+n_y[k];
				
				if(nx>=0 && nx<x && ny>=0 && ny<y && !check[nx][ny]) {
					cnt++;
					check[nx][ny] = true;
					q.push(make_pair(nx,ny));
				}
			}
			bit<<=1;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>y>>x;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++) cin>>arr[i][j];
		
	int area = 0, cnt = 0;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++) {
			if(!check[i][j]) {
				area = max(area, solve(i,j));
				cnt++;
			}
		}
	cout<<cnt<<"\n";
	cout<<area<<"\n";
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++) {
			for(int k=1;k<=8;k<<=1) {
				memset(check,false,sizeof(check));
				arr[i][j] -= k;
				area = max(area, solve(i,j));
				arr[i][j] += k;
			}
		}
	}
	cout<<area<<"\n";
	return 0;
}
