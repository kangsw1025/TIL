#include<iostream>
#include<stack>
#include<string>
using namespace std;

int arr[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string w;
	stack<double> st;
	cin >> n;
	cin >> w;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < w.length(); i++) {
		if (w[i] == '+' || w[i] == '-' || w[i] == '*' || w[i] == '/') {
			if (w[i] == '+') {
				double s = st.top();
				st.pop();
				double f = st.top();
				st.pop();
				st.push(f + s);
			}
			else if (w[i] == '-') {
				double s = st.top();
				st.pop();
				double f = st.top();
				st.pop();
				st.push(f - s);
			}
			else if (w[i] == '*') {
				double s = st.top();
				st.pop();
				double f = st.top();
				st.pop();
				st.push(f * s);
			}
			else if (w[i] == '/') {
				double s = st.top();
				st.pop();
				double f = st.top();
				st.pop();
				st.push(f / s);
			}
		}
		else st.push(arr[w[i] - 'A']);
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;
}