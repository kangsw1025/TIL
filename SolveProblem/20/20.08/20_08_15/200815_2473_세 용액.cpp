#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

long long arr[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    
    long long sum = 3000000001;
    long long dif;
    
    pair<pair<int, int>, int> ans;
    
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;
        while (1) {
            if (j >= k) break;

            dif = arr[i] + arr[j] + arr[k];

            if (llabs(dif) < sum) {
                sum = llabs(dif);
                ans.first.first = arr[i];
                ans.first.second = arr[j];
                ans.second = arr[k];
            }

            if (dif < 0) j++;
            else k--;
        }
    }


    cout << ans.first.first << ' ' << ans.first.second << ' ' << ans.second;
    return 0;
}