function cmp(a, b) {
  var rst = a.length;
  for (let i = 0; i < a.length; i++) if (a[i] == b[i]) rst--;

  if (rst <= 1) return true;
  return false;
}

function solution(begin, target, words) {
  var answer = 51;
  var visit = new Array(51).fill(false);

  function dfs(w, t, c) {
    if (w == t) return c;

    var rt = -1;

    for (let i = 0; i < words.length; i++) {
      if (visit[i]) continue;

      if (cmp(w, words[i])) {
        visit[i] = true;
        var rst = dfs(words[i], t, c + 1);
        visit[i] = false;
        if (rst != -1) {
          if (rt == -1) rt = rst;
          else rt = Math.min(rt, rst);
        }
      }
    }

    return rt;
  }

  for (let i = 0; i < words.length; i++) {
    if (cmp(begin, words[i])) {
      visit[i] = true;
      var rst = dfs(words[i], target, 1);
      if (rst != -1) answer = Math.min(answer, rst);
      visit[i] = false;
    }
  }

  if (answer == 51) return 0;

  return answer;
}
