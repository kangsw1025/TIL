#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n, student, index = 1;
	stack<int> line;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> student;
		while (!line.empty()) {
			if (line.top() == index) {
				index++;
				line.pop();
			}
			else break;
		}
		if (student == index) index++;
		else line.push(student);
	}
	while (!line.empty()) {
		if (line.top() == index) {
			index++;
			line.pop();
		}
		else break;
	}
	if (line.empty()) cout << "Nice";
	else cout << "Sad";
	return 0;
}