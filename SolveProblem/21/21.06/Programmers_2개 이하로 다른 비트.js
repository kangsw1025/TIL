function solution(numbers) {
    var answer = [];
    for(let i = 0 ;i<numbers.length;i++) {
        var num = '0' + numbers[i].toString(2);
        if(num[num.length-1]==='0') answer.push(numbers[i]+1);
        else {
            for(let k = num.length-1;k>=0;k--) {
                if(num[k]==='0') {
                    answer.push(parseInt(num.substring(0,k)+"1"+"0"+num.substring(k+2, num.length),2));
                    break;
                }
            }
        }
    }
    return answer;
}