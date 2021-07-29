function xy(num) {
  if (num == 1) return [1, 1];
  else if (num == 2) return [2, 1];
  else if (num == 3) return [3, 1];
  else if (num == 4) return [1, 2];
  else if (num == 5) return [2, 2];
  else if (num == 6) return [3, 2];
  else if (num == 7) return [1, 3];
  else if (num == 8) return [2, 3];
  else if (num == 9) return [3, 3];
  else if (num == "*") return [1, 4];
  else if (num == 0) return [2, 4];
  else if (num == "#") return [3, 4];
}

function comp(num, left, right) {
  var new_left = xy(left);
  var new_right = xy(right);
  var new_num = xy(num);

  var cmp_left =
    Math.abs(new_left[0] - new_num[0]) + Math.abs(new_left[1] - new_num[1]);
  var cmp_right =
    Math.abs(new_right[0] - new_num[0]) + Math.abs(new_right[1] - new_num[1]);

  if (cmp_left > cmp_right) return "R";
  else if (cmp_left < cmp_right) return "L";
  return "eq";
}

function solution(numbers, hand) {
  var answer = "";
  let left = "*",
    right = "#";
  for (let i = 0; i < numbers.length; i++) {
    if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
      answer += "L";
      left = numbers[i];
    } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
      answer += "R";
      right = numbers[i];
    } else {
      var rst = comp(numbers[i], left, right);
      if (rst == "L") {
        answer += "L";
        left = numbers[i];
      } else if (rst == "R") {
        answer += "R";
        right = numbers[i];
      } else {
        if (hand == "right") {
          answer += "R";
          right = numbers[i];
        } else {
          answer += "L";
          left = numbers[i];
        }
      }
    }
  }
  return answer;
}
