function cnt(s, idx) {
  var dif = new Array(781, 156, 31, 6, 1);

  if (s == "A") return 0;
  if (s == "E") return 1 * dif[idx];
  if (s == "I") return 2 * dif[idx];
  if (s == "O") return 3 * dif[idx];
  if (s == "U") return 4 * dif[idx];
}

function solution(word) {
  var answer = 0;

  for (let i = 0; i < word.length; i++) answer += 1 + cnt(word[i], i);

  return answer;
}
