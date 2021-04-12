function solution(n) {
    var answer = 0;
    for(let i = 1;i<=Math.sqrt(n);i++)
        if(n%i==0) {
            if(i != n/i) {
                answer += (i + n/i);
            }
            else answer += i;
        }
    return answer;
}