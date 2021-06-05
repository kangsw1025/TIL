function solution(n) {
    var answer = 0;
    var dp = new Array(2001).fill(0);
    
    dp[1] = 1;
    dp[2] = 2;
    for(let i = 3;i<=2000;i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    answer = dp[n];
    return answer;
}