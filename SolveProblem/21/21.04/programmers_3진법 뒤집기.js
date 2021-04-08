function solution(n) {
    var answer = 0;
  
    let num = "";
    while (1) {
      num += (n % 3) + "";
      n = parseInt(n / 3);
      if (n < 1) break;
    }
    for (let i = num.length - 1; i >= 0; i--)
      answer += num[i] * 1 * Math.pow(3, num.length - i - 1);
    console.log(answer);
  }
  
  solution(45);
  