function solution(n, stations, w) {
  var answer = 0;
  var range = 2 * w + 1;
  stations.unshift(0 - w);
  stations.push(n + 1 + w);
  for (let i = 0; i < stations.length - 1; i++) {
    var left = stations[i] + w + 1;
    var right = stations[i + 1] - w - 1;
    answer += Math.ceil(Math.max(0, right - left + 1) / range);
  }

  return answer;
}
