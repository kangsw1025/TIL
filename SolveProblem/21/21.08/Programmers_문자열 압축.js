function solution(s) {
  var answer = s.length;
  let lengthArray = [];

  for (let i = 0; i < s.length / 2; i++) {
    let slength = i + 1;
    let repeatString = 1;
    let newString = "";

    for (let j = 0; j < s.length; j += slength) {
      let curString = s.substring(j, j + slength);
      let nextString = s.substring(j + slength, j + 2 * slength);

      if (curString == nextString) {
        repeatString++;
      } else {
        if (repeatString != 1) newString = newString + repeatString + curString;
        else newString += curString;
        repeatString = 1;
      }
    }

    answer = Math.min(answer, newString.length);
  }

  return answer;
}
