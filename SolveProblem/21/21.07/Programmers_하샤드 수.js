function solution(x) {
  var answer = true;
  var sum = 0,
    n = x;
  while (x >= 1) {
    sum += x % 10;
    x = parseInt(x / 10);
  }
  if (n % sum !== 0) answer = false;
  return answer;
}
