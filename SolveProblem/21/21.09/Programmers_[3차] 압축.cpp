#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> vec;
    for(int i=0;i<='z'-'a';i++) {
        string word = "";
        word += 'A'+i;
        vec.push_back(word);
    }
    
    for(int i=0;i<msg.length();i++) {
        string word = "";
        int idx;
        while(i<msg.length()) {
            word += msg[i];
            auto itr = find(vec.begin(),vec.end(),word);
            if(itr!=vec.end()) {
                idx = itr - vec.begin();
                i++;
            }
            else {
                i--;
                break;
            }
        }
        vec.push_back(word);
        answer.push_back(idx + 1);
    }
    
    return answer;
}