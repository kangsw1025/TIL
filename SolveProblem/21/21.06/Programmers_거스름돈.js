function solution(n, money) {
    var answer = 0;
    var dp = new Array(n+1).fill(0);
    dp[0] = 1;
    
    for(let i = 0 ;i<money.length;i++)
        for(let j = 0 ;j<=n;j++) 
            if(j>=money[i])
                dp[j] = (dp[j] + dp[j-money[i]])%1000000007;
    answer = dp[n];
    return answer;
}