#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    int dif = 'z' - 'a' + 1;
    
    for(int i=0;i<s.length();i++) {
        if(s[i]>='a' && s[i]<='z') {
            s[i] = 'a' + (s[i] - 'a' + n) % dif;
        }
        else if(s[i]>='A' && s[i] <='Z') {
            s[i] = 'A' + (s[i] - 'A' + n) % dif;
        }
    }
    return s;
}