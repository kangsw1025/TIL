function solution(N, stages) {
  var answer = [];
  var alive = new Array(N + 1).fill(0);
  var clear = new Array(N + 1).fill(0);

  for (let i = 1; i <= N; i++) answer.push(i);

  for (let i = 0; i < stages.length; i++) {
    for (let j = 1; j < stages[i]; j++) {
      alive[j]++;
      clear[j]++;
    }
    alive[stages[i]]++;
  }

  answer.sort((a, b) => clear[a] / alive[a] - clear[b] / alive[b]);

  return answer;
}
