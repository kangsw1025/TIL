function solution(s) {
  var answer = "";
  var words = s.split(" ");

  for (let i = 0; i < words.length; i++) {
    var word = words[i];
    for (let j = 0; j < word.length; j++) {
      if (j % 2 == 0) answer += word[j].toUpperCase();
      else answer += word[j].toLowerCase();
    }
    if (i != words.length - 1) answer += " ";
  }
  return answer;
}
