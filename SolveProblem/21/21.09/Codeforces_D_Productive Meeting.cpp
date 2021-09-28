#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
using namespace std;
 
int arr[200001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if(num!=0) q.push({ num,i + 1 });
		}
 
		while (q.size()>=2) {
			pair<int, int> p1 = q.top();
			q.pop();
			pair<int, int> p2 = q.top();
			q.pop();
 
			if (p1.first && p2.first) {
				v.push_back({ p1.second,p2.second });
				p1.first--;
				p2.first--;
				if(p1.first) q.push(p1);
				if(p2.first) q.push(p2);
			}
		}
 
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) 
			cout << v[i].first << ' ' << v[i].second << "\n";
	}
 
	return 0;
}