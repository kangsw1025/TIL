#include <string>
#include <vector>
#include <set>

using namespace std;

int si;
set<set<string>> Se;
vector<string> v[9];

void dfs(set<string> s, int depth) {
    
    if(depth ==si) {
        Se.insert(s);
        return;
    }
    
    for(int i=0;i<v[depth].size();i++) {
        if(s.find(v[depth][i])==s.end()) {
            s.insert(v[depth][i]);
            dfs(s,depth+1);
            s.erase(v[depth][i]);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    si = banned_id.size();
    
    for(int i=0;i<banned_id.size();i++) {
        for(int j=0;j<user_id.size();j++) {
            if(banned_id[i].length() != user_id[j].length()) continue;
            
            bool check = true;
            
            for(int k=0;k<user_id[j].length();k++) {
                if(banned_id[i][k]=='*') continue;
                
                if(banned_id[i][k] != user_id[j][k]) {
                    check = false;
                    break;
                }
            }
            
            if(check) v[i].push_back(user_id[j]);
        }
    }
    
    set<string> s;
    for(int i=0;i<v[0].size();i++) {
        s.insert(v[0][i]);
        dfs(s,1);
        s.erase(v[0][i]);
    }
    
    answer = Se.size();
    return answer;
}