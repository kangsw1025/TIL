function solution(s) {
  var answer = [];

  for (var words of s) {
    const stack = [];
    const arr = words.split("");
    let cnt = 0;

    for (let i = 0; i < arr.length; i++) {
      const third = arr[i];

      if (stack.length > 1) {
        const second = stack.pop();
        const first = stack.pop();

        if (first == "1" && second == "1" && third == "0") {
          cnt++;
          continue;
        } else {
          stack.push(first, second, third);
        }
      } else {
        stack.push(third);
      }
    }

    if (!cnt) {
      answer.push(words);
    } else {
      const list = [];
      const keyword = "011";

      while (stack.length) {
        const last = stack.pop();

        if (last == "0") {
          stack.push(last);
          break;
        }

        list.push(last);
      }

      while (cnt) {
        list.push(...keyword);
        cnt--;
      }

      while (stack.length) {
        list.push(stack.pop());
      }

      const rst = list.reverse().join("");
      answer.push(rst);
    }
  }

  return answer;
}
