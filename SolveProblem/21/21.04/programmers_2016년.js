function solution(a, b) {
  var answer = "";
  let date = 0;
  date += b - 1;
  while (a != 1) {
    if (a <= 8) {
      if (a % 2 == 0) {
        date += 31;
      } else {
        if (a == 3) date += 29;
        else date += 30;
      }
    }
    else {
        if (a % 2 == 1) {
            date += 31;
          } else {date += 30;
          }
    }
    a--;
  }
  date = date % 7;
  const array = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"];
  answer = array[date];
  return answer;
}