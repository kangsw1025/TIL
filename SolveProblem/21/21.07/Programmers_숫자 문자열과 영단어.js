function solution(s) {
  var answer = 0;
  var word = "";
  function change(word) {
    if (word == "zero") return 0;
    else if (word == "one") return 1;
    else if (word == "two") return 2;
    else if (word == "three") return 3;
    else if (word == "four") return 4;
    else if (word == "five") return 5;
    else if (word == "six") return 6;
    else if (word == "seven") return 7;
    else if (word == "eight") return 8;
    else if (word == "nine") return 9;
    return -1;
  }

  for (let i = 0; i < s.length; i++) {
    if (s[i] >= "0" && s[i] <= "9") answer = answer * 10 + parseInt(s[i]);
    else {
      word += s[i];
      var rst = change(word);
      if (rst != -1) {
        word = "";
        answer = answer * 10 + rst;
      }
    }
  }
  return answer;
}
