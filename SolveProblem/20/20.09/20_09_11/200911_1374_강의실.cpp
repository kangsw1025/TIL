#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > q;
	priority_queue<int, vector<int>, greater<int> > st;
	for(int i=0;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		q.push(make_pair(b,c));
	}
	st.push(q.top().second);
	q.pop();
	while(!q.empty()) {
		int start = q.top().first;
		int end = q.top().second;
		q.pop();
		if(st.top()<=start)
			st.pop();
	
		st.push(end);
	}
	cout<<st.size();
	return 0;
}
