function solution(answers) {
    var answer = [];
    let a = 0, b = 0, c = 0;
    for(let i = 0;i<answers.length;i++)
        if(answers[i]%5 == (i+1)%5) a++;
    console.log(a);
    let now = 1;
    for(let i = 0;i<answers.length;i++) {
        if(i%2) {
            if(answers[i]==now) b++;
            now++;
            if(now==2) now = 3;
            if(now>5) now = 1;
        }
        else {
            if(answers[i]==2) b++;
        }
    }
    console.log(b)
    now = 3;
    let use = 0;
    for(let i = 0;i<answers.length;i++) {
        if(answers[i]==now) c++;
        use ++;
        if(use ==2) {
            use = 0;
            if(now ==3) now = 1;
            else if(now ==5) now = 3;
            else if(now==2) now = 4;
            else now ++;
        }
    }
    console.log(c);
    let most = Math.max(a,Math.max(b,c));
    if(a==most) answer.push(1);
    if(b==most) answer.push(2);
    if(c==most) answer.push(3);
    return answer;
}