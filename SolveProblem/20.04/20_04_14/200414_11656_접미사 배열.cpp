#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string word;
	cin >> word;
	string* wo = new string[word.length()];
	for(int i=0;i<word.length();i++) 
		for (int j = i; j < word.length(); j++) {
			wo[i] += word[j];
		}
	sort(wo, wo + word.length());
	for (int i = 0; i < word.length(); i++) cout << wo[i] << "\n";
	return 0;
}