#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int arr[1000001];
int check[1000001];
vector<int> vec;

int go(int num){
    int rst = 0;
    for(int i = 1; i <= sqrt(num); i++){
        if(num % i == 0){
            rst += arr[i];
            if(num / i != i){
                rst += arr[num / i];
            }
        }
    }
    return rst;
}

int main() {
    ios::sync_with_stdio();
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        arr[num]++;
        vec.push_back(num);
    }
    for(int i = 0; i < n; i++){
        if(check[vec[i]] != 0){
            cout << check[vec[i]] << "\n";
            continue;
        }
        check[vec[i]] = go(vec[i]) - 1;
        cout << check[vec[i]] << "\n";
    }
    return 0;
}
