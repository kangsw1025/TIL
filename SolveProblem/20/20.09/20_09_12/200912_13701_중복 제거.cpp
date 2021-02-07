#include<iostream>
#include<bitset>
using namespace std;

int arr[(1<<25)/32];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(~cin>>n) {
		int num = n/32;
		int mo = 1<<(n%32);
		if(!(arr[num] & mo)) {
			arr[num] += mo;
			cout<<n<<' ';
		}
	}
	return 0;
}
