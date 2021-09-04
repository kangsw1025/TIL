#include <string>
#include <vector>
#include<iostream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> p1, pair<int,string> p2) {
    return p1.first>p2.first;
}

bool cp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first==p2.first) {
        p1.second<p2.second;
    }
    return p1.first>p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> cnt;
    map<string, vector<pair<int,int>>> mp;
    
    for(int i=0;i<plays.size();i++) {
        string gen = genres[i];
        int play = plays[i];
        
        if(cnt[gen]) cnt[gen] += play;
        else cnt[gen] = play;
        
        mp[gen].push_back({play,i});
    }
    vector<pair<int,string>> vec;
    
    for(auto itr = cnt.begin();itr!=cnt.end();itr++)
        vec.push_back({itr->second, itr->first});
    
    sort(vec.begin(),vec.end(),cmp);
    
    for(auto itr = mp.begin();itr!=mp.end();itr++) {
        sort(itr->second.begin(),itr->second.end(), cp);
    }
    
    for(int i=0;i<vec.size();i++) {
        string gen = vec[i].second;
        
        vector<pair<int,int>> v = mp[gen];
        
        for(int i=0;i< (v.size()>=2 ? 2 : v.size());i++)
            answer.push_back(v[i].second);
    }
    
    return answer;
}