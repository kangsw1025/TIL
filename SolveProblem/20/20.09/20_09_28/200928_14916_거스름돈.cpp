#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	if(n==1 || n==3) cout<<-1;
	else {
		int five = 0 , two = 0;
		five += n/5;
		n %= 5;
		if(n%2) {
			five--;
			two += (n+5)/2;
		}
		else two += n/2;
		cout<<five+two;
	}
	return 0;
}
