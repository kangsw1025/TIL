#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n,s,h;
vector<int> vec;
long long ans;
map<int, int> mp;

void solvel(int idx, int sum) {
	if(idx==h) {
		mp[sum]++;
		return;
	}
	solvel(idx+1,sum);
	solvel(idx+1,sum+vec[idx]);
}

void solver(int idx, int sum) {
	if(idx==n) {
		ans += mp[s-sum];
		return;
	}
	solver(idx+1,sum);
	solver(idx+1,sum+vec[idx]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>s;
	h = n/2;
	vec.resize(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	solvel(0,0);
	solver(h,0);
	if(s==0) ans--;
	cout<<ans;
	return 0;
}
