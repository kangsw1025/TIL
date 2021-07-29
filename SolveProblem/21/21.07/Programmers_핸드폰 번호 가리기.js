function solution(phone_number) {
  var answer = "";
  var phone_length = phone_number.length;
  var back4 = phone_number.substring(phone_length - 4, phone_length);
  for (let i = 0; i < phone_length - 4; i++) answer += "*";
  answer += back4;
  return answer;
}
