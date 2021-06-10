function solution(n) {
    var answer = 0;
    var cntone = n.toString(2).split('').filter(num=>num==='1').length;
    for(let i = n+1;i>=0;i++) {
        if(i.toString(2).split('').filter(num=>num==='1').length===cntone) {
            answer = i;
            break;
        }
    }
    return answer;
}