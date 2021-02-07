#include<iostream>
#include<string>
using namespace std;

int main() {
	string line;
	cin>>line;
	
	int idx = 0;
	bool check = true;
	for(int i=0;i<line.length();i++) {
		if(line[i]=='X') idx++;
		else {
			if(idx==2) {
				for(int j=1;j<=2;j++) line[i-j]='B';
				idx = 0;
			}
			else if(idx!=0){
				check = false;
				break;
			}
		}
		if(idx==4) {
			for(int j=0;j<4;j++) line[i-j]='A';
			idx = 0;
		}
	}
	if(idx) {
		if(idx==2) {
			for(int j=1;j<=2;j++) line[line.length()-j]='B';
		}
		else check = false;
	}
	if(check) cout<<line;
	else cout<<-1;
	return 0;
}
