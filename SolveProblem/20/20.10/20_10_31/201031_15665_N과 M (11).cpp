#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[8];
int n,m;
vector<int> vec;

void solve(int idx) {
	if(idx==m) {
		for(int i=0;i<m;i++) cout<<arr[i]<<' ';
		cout<<"\n";
		return;
	}
	
	for(int i=0;i<vec.size();i++) {
		arr[idx] = vec[i];
		solve(idx+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		vec.push_back(num);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	
	for(int i=0;i<vec.size();i++) {
		arr[0] = vec[i];
		solve(1);
	}
}
