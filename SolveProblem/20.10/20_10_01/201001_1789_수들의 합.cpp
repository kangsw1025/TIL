#include<iostream>
using namespace std;

long long n;

int solve() {
	int num = 1;
	int rst = 0;
	long long sum = 0;
	
	while(1) {
		sum += num;
		rst++;
		if(sum>n) {
			rst--;
			break;
		}
		num++;
	}
	return rst;
}

int main() {
	cin>>n;
	cout<<solve();
	return 0;
}
