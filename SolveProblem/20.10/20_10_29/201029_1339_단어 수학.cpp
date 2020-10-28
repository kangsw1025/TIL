#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n;
int alp[26];
vector<string> vec;

bool cmp(int a, int b) {
	return a>b;
}

void solve() {
	for(int i=0;i<n;i++) {
		string word = vec[i];
		int pow = 1;
		for(int j=word.length()-1;j>=0;j--) {
			int tmp = word[j]-'A';
			alp[tmp] += pow;
			pow *= 10;
		}
	}
	sort(alp,alp+26,cmp);
	
	int ans = 0;
	int num = 9;
	for(int i=0;i<26;i++) {
		if(alp[i]==0) break;
		ans += alp[i]*num;
		num--;
	}
	cout<<ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) {
		string word;
		cin>>word;
		vec.push_back(word);
	}
	
	solve();
	return 0;
}
