function solution(a, b) {
    var answer = 0;
    if(a>b) {
        var tmp = a;
        a = b;
        b = tmp;
    }
    for(let i = a;i<=b;i++) answer += i;
    return answer;
}