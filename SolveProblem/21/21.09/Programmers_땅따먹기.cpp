#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int si = land.size();
    for(int i=0;i<4;i++)
        dp[0][i] = land[0][i];
    
    for(int i=1;i<si;i++) {
        dp[i][0] = land[i][0] + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
        dp[i][1] = land[i][1] + max(dp[i-1][0],max(dp[i-1][2],dp[i-1][3]));
        dp[i][2] = land[i][2] + max(dp[i-1][1],max(dp[i-1][0],dp[i-1][3]));
        dp[i][3] = land[i][3] + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][0]));
    }

    answer = max(max(dp[si-1][0],dp[si-1][1]),max(dp[si-1][2],dp[si-1][3]));
    return answer;
}