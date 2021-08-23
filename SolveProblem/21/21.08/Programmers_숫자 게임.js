function solution(A, B) {
  var answer = 0;
  var idx = 0;

  A.sort((a, b) => b - a);
  B.sort((a, b) => b - a);

  for (let i = 0; i < A.length; i++) {
    var point = A[i];
    if (B[idx] > point) {
      idx++;
      answer++;
    }
  }
  return answer;
}
