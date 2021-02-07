#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<pair<string, int>, pair<int, int> > a, pair<pair<string, int>, pair<int, int> > b) {
	if(a.second.second<=b.second.second) {
		if(a.second.second==b.second.second) {
			if(a.second.first<=b.second.first) {
				if(a.second.first==b.second.first) {
					return a.first.second<b.first.second;
				}
				return true;
			}
		}
		return true;
	}	
	return false;
}

int main() {
	vector<pair<pair<string, int>, pair<int, int> > > vec;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string name;
		int a,b,c;
		cin>>name>>a>>b>>c;
		vec.push_back({{name,a}, {b,c}});
	}
	sort(vec.begin(),vec.end(), cmp);
	cout<<vec[vec.size()-1].first.first<<"\n";
	cout<<vec[0].first.first;
	return 0;
}
