#include <iostream>
#include <stack>
using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;
	stack<char> t,t2;
	int n, cnt = 1;
	bool al = true;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	st.push(0);
	int k = 1;
	while (cnt <= n) {

		if (st.top() < arr[cnt]) {
			st.push(k++);
			t.push('+');
		}
		else if (st.top() == arr[cnt]) {
			st.pop();
			cnt++;
			t.push('-');
		}
		else {
			al = false;
			break;
		}

	}
	if (al == false) cout << "NO";
	else {
		while (!t.empty()) {
			t2.push(t.top());
			t.pop();
		}
		while (!t2.empty()) {
			cout << t2.top() << "\n";
			t2.pop();
		}
	}
}