#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	priority_queue<ll,vector<ll>, greater<ll> > q;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		q.push(num);
	}
	for(int i=0;i<m;i++) {
		ll n1 = q.top();
		q.pop();
		ll n2 = q.top();
		q.pop();
		q.push(n1+n2);
		q.push(n1+n2);
	}	
	
	ll ans = 0;
	while(!q.empty()) {
		ans += q.top();
		q.pop();
	}
	cout<<ans;
	return 0;
}
