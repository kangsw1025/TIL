#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> a,b,cha,hab;
    
    for(int i=0;i<str1.length()-1;i++) {
        char f = tolower(str1[i]);
        char s = tolower(str1[i+1]);
        if(f>='a' && f<='z' && s>='a' && s<='z') {
            string w = "";
            w += f;
            w += s;
            a.push_back(w);
        }
    }
    
    for(int i=0;i<str2.length()-1;i++) {
        char f = tolower(str2[i]);
        char s = tolower(str2[i+1]);
        if(f>='a' && f<='z' && s>='a' && s<='z') {
            string w = "";
            w += f;
            w += s;
            b.push_back(w);
        }
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int cn = 0;
    
    int aidx = 0, bidx = 0;
    
    while(aidx < a.size() && bidx < b.size()) {
        if(a[aidx]==b[bidx]) {
            cn++;
            hab.push_back(a[aidx]);
            aidx++;
            bidx++;
        }
        else if(a[aidx]> b[bidx]) {
            hab.push_back(b[bidx++]);
        }
        else hab.push_back(a[aidx++]);
    }
    
    for(int i=aidx;i<a.size();i++)
        hab.push_back(a[i]);
    
    for(int i=bidx;i<b.size();i++)
        hab.push_back(b[i]);
    
    int hn = hab.size();
    
    if(hn==cn) return 65536;
    
    double rst = (double)cn / (double)hn;
    answer = rst * 65536;
    return answer;
}