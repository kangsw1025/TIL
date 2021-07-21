function solution(places) {
  var answer = [];
  for (let i = 0; i < places.length; i++) {
    var arr = places[i];
    var save = true;
    for (let j = 0; j < 5; j++) {
      if (save == false) break;
      for (let k = 0; k < 5; k++) {
        if (arr[j][k] === "P") {
          if (j < 4) {
            if (arr[j + 1][k] === "P") {
              save = false;
              break;
            }
          }
          if (j < 3) {
            if (arr[j + 2][k] === "P") {
              if (arr[j + 1][k] != "X") {
                save = false;
                break;
              }
            }
          }
          if (k < 4) {
            if (arr[j][k + 1] === "P") {
              save = false;
              break;
            }
          }
          if (k < 3) {
            if (arr[j][k + 2] === "P") {
              if (arr[j][k + 1] != "X") {
                save = false;
                break;
              }
            }
          }
          if (j < 4 && k < 4) {
            if (arr[j + 1][k + 1] === "P") {
              if (arr[j + 1][k] != "X" || arr[j][k + 1] != "X") {
                save = false;
                break;
              }
            }
          }
          if (j < 4 && k > 0) {
            if (arr[j + 1][k - 1] === "P") {
              if (arr[j + 1][k] != "X" || arr[j][k - 1] != "X") {
                save = false;
                break;
              }
            }
          }
        }
      }
    }
    if (save) answer.push(1);
    else answer.push(0);
  }
  return answer;
}
