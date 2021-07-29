function solve(n, m) {
  var left = n % m;
  if (left == 0) return m;
  else return solve(m, left);
}

function solution(n, m) {
  var answer = [];
  var gcd;
  if (n > m) gcd = solve(n, m);
  else gcd = solve(m, n);
  answer = [gcd, (n * m) / gcd];
  return answer;
}
