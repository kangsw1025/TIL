#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = (brown-4) / 2;
    for(int i = sum/2;i>=1;i--) {
        if(i*(sum-i)==yellow) {
            answer.push_back(sum-i+2);
            answer.push_back(i+2);
            break;
        }
    }
    return answer;
}