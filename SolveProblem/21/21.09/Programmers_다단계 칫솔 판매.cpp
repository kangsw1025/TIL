#include <string>
#include <vector>
#include <map>

using namespace std;

int arr[100001], getMoney[100001];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string,int> mp;
    for(int i=0;i<enroll.size();i++)
        mp[enroll[i]] = i+1;
    
    for(int i=0;i<referral.size();i++) {
        string name = referral[i];
        
        if(name=="-") arr[i+1] = 0;
        else arr[i+1] = mp[name];
    }
    
    for(int i=0;i<seller.size();i++) {
        int idx = mp[seller[i]];
        int money = amount[i]*100;
        
        int left = money/10;
        getMoney[idx] += money-left;
        
        int parent = arr[idx];
        while(1) {
            money = left;
            left = money/10;
            getMoney[parent] += money-left;
            if(arr[parent]==parent) break;
            parent = arr[parent];
        }
    }
    for(int i=1;i<=enroll.size();i++) answer.push_back(getMoney[i]);
    return answer;
}