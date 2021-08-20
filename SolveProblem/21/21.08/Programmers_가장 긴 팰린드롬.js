function solution(s) {
  for (let i = s.length; i > 1; i--) {
    for (let st = 0; st + i <= s.length; st++) {
      var check = true;

      for (var j = 0; j < i / 2; j++) {
        if (s[st + j] != s[st + i - j - 1]) {
          check = false;
          break;
        }
      }

      if (check) return i;
    }
  }

  return 1;
}
