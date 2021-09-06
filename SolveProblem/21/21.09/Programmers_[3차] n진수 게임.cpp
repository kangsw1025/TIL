#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char changer(int val) {
    if(val<=9) return val+'0';
    else if(val==10) return 'A';
    else if(val==11) return 'B';
    else if(val==12) return 'C';
    else if(val==13) return 'D';
    else if(val==14) return 'E';
    return 'F';
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    vector<int> mod;
    vector<char> arr;
    mod.push_back(1);
    
    for(int i=0;mod[i]*n<=1000000;i++) mod.push_back(mod[i] * n);
    
    arr.push_back('0');
    int num = 1;
    while(arr.size()<=1000000) {
        int val = num;
        
        auto itr = upper_bound(mod.begin(),mod.end(),val);
        int mo = *itr / n;
        while(mo>=1) {
            arr.push_back(changer(val / mo));
            val = val% mo;
            mo/=n;
        }
        
        num++;
    }
    
    int start = p-1;
    for(int i=0;i<t;i++)
        answer += arr[start+ m*i];
    return answer;
}