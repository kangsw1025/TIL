#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class segment {
public:
	int n;
	vector<long long> sum;
	segment(vector<long long> &vec) {
		n = vec.size();
		sum.resize(n * 4);
		init(vec, 0, n - 1, 1);
	}

	long long init(vector<long long>& vec, int left, int right, int node) {
		if (left == right) return sum[node] = vec[left];

		int mid = (left + right) / 2;
		long long left_tree = init(vec, left, mid, node * 2);
		long long right_tree = init(vec, mid + 1, right, node * 2 + 1);
		return sum[node] = (left_tree* right_tree)%1000000007;
	}

	long long query(int left, int right, int node, int start, int end) {
		if (right < start || left > end) return 1;
		if (left <= start && right >= end) return sum[node];

		int mid = (start + end) / 2;
		return (query(left, right, node * 2, start, mid) * query(left, right, node * 2 + 1, mid + 1, end))%1000000007;
	}
	long long query(int l, int r) {
		return query(l - 1, r - 1, 1, 0, n - 1);
	}
	long long update(int index, int newval, int node, int start, int end) {
		if (index<start || index>end) return sum[node];
		if (start == end) return sum[node] = newval;

		int mid = (start + end) / 2;
		return sum[node] = (update(index, newval, node * 2, start, mid) * update(index, newval, node * 2 + 1, mid + 1, end))%1000000007;
	}
	long long update(int index, int newval) {
		return update(index - 1, newval, 1, 0, n - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q, k;
	cin >> n >> q>>k;

	vector<long long> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	segment tree(v);

	for (int i = 0; i < q+k; i++) {
		int a,b,c;
        cin>>a>>b>>c;
        if(a==1) tree.update(b,c);
        else {
            if(b>c) swap(b,c);
            cout<<tree.query(b,c)<<"\n";
        }
	}
	return 0;
}
