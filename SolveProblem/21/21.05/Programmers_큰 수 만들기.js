function solution(number, k) {
    var answer = '';
    var numbers = number.split('');
    var arr = [];
    for(let i = 0;i<numbers.length;i++) {
        let now = numbers[i];
        
        while(1) {
            if(k<=0 || arr.length===0) break;
            if(arr[arr.length-1]<now) {
                arr.pop();
                k--;
            }
            else break;
        }
        
        arr.push(now);
    }
    arr.splice(arr.length-k,k);
    answer = arr.join('');
    return answer;
}