function solution(n) {
    var answer = [];
    
    function hanoi(num, start, mid, end) {
        if(num===1) {
            answer.push([start,end]);
            return;
        }
        
        hanoi(num-1,start,end,mid);
        answer.push([start,end]);
        hanoi(num-1,mid,start,end);
    }
    hanoi(n,1,2,3);
    return answer;
}