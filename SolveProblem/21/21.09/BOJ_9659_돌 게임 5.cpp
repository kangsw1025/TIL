#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  cin>>n;
  if(n%2) cout<<"SK";
  else cout<<"CY";
  return 0;
}