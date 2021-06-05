function solution(n) {
    var answer = 0;
    var arr = new Array(10001).fill(0);
    
    for(let i = 1;i<=10000;i++) {
        var now = 0;
        for(let j = i;now+j<=10000;j++) {
            now+=j;
            arr[now]++;
        }
    }
    answer = arr[n];
    return answer;
}