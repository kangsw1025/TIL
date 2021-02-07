#include<iostream>
using namespace std;

int solve(int m) {
	int count = 0, m1 = 0, m2 = 1;
	do{
		int tmp = m1;
		m1 = m2;
		m2 = (tmp+m1)%m;
		count++;
	} while(m1!=0 || m2 !=1);
	return count;
}

int main() {
	int p,n,m;
	cin>>p;
	for(int i=0;i<p;i++) {
		cin>>n>>m;
		cout<<n<<' '<<solve(m)<<"\n";
	}
}
