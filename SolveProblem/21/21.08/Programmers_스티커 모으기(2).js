function solution(sticker) {
  var answer = 0;

  if (sticker.length == 1) return sticker[0];

  var dp = new Array(100001).fill(0);

  dp[0] = sticker[0];
  dp[1] = sticker[0];
  for (let i = 2; i < sticker.length - 1; i++)
    dp[i] = Math.max(dp[i - 1], dp[i - 2] + sticker[i]);
  answer = Math.max(answer, dp[sticker.length - 2]);

  dp[0] = 0;
  dp[1] = sticker[1];

  for (let i = 2; i < sticker.length; i++)
    dp[i] = Math.max(dp[i - 1], dp[i - 2] + sticker[i]);
  answer = Math.max(answer, dp[sticker.length - 1]);
  return answer;
}
