#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<pair<int,int> > vec;
	
	for(int i=1;i<=8;i++) {
		int n;
		cin>>n;
		vec.push_back({n, i});
	}
	sort(vec.begin(),vec.end());
	int sum = 0;
	vector<int> idx;
	for(int i=3;i<=7;i++) {
		sum +=vec[i].first; 
		idx.push_back(vec[i].second);
	}
	sort(idx.begin(),idx.end());
	cout<<sum<<"\n";
	for(int i=0;i<5;i++) cout<<idx[i]<<' ';
	return 0;
}
