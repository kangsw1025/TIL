function solution(left, right) {
  var answer = 0;
  var dp = new Array(1001).fill(2);
  dp[0] = 0;
  dp[1] = 1;
  for (let i = 2; i <= 1000; i++) {
    for (let j = 2; j < i; j++) if (i % j == 0) dp[i]++;
  }
  for (let i = left; i <= right; i++) {
    if (dp[i] % 2) answer -= i;
    else answer += i;
  }
  return answer;
}
