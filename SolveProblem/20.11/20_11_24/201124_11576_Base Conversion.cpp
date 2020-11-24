#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a,b;
	int cnt;
	int num[25];
	
	cin>>a>>b;
	cin>>cnt;
	for(int i=0;i<cnt;i++) cin>>num[i];
	
	int dec = 0;
	for(int i=0;i<cnt;i++) dec = dec*a+num[i];
	
	vector<int> vec;
	while(dec!=0) {
		vec.push_back(dec%b);
		dec/=b;
	}
	for(int i=vec.size()-1;i>=0;i--) {
		cout<<vec[i]<<' ';
	}
	return 0;
}
