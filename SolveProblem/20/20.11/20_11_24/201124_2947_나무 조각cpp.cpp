#include<iostream>
#include<string>
using namespace std;

string word="";

void print() {
	for(int i=0;i<5;i++) cout<<word[i]<<' ';
	cout<<"\n";
}

int main() {
	
	for(int i=0;i<5;i++) {
		char w;
		cin>>w;
		word+=w;
	}
	while(word!="12345") {
		if(word[0]>word[1]) {
			char tmp = word[0];
			word[0] = word[1];
			word[1] = tmp;
			print();
		}
		if(word[1]>word[2]) {
			char tmp = word[1];
			word[1] = word[2];
			word[2] = tmp;
			print();
		}
		if(word[2]>word[3]) {
			char tmp = word[2];
			word[2] = word[3];
			word[3] = tmp;
			print();
		}
		if(word[3]>word[4]) {
			char tmp = word[3];
			word[3] = word[4];
			word[4] = tmp;
			print();
		}
	}
	return 0;
}
