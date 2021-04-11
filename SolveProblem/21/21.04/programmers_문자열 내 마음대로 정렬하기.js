function solution(strings, n) {
  var answer = [];
  for (let i = 0; i < strings.length; i++) {
    for (let j = 0; j < strings.length - 1; j++) {
      if (strings[j][n] > strings[j + 1][n]) {
        var string = strings[j];
        strings[j] = strings[j + 1];
        strings[j + 1] = string;
      } else if (strings[j][n] == strings[j + 1][n]) {
        if (strings[j] > strings[j + 1]) {
          var string = strings[j];
          strings[j] = strings[j + 1];
          strings[j + 1] = string;
        }
      }
    }
  }
  answer = strings;
  return answer;
}
