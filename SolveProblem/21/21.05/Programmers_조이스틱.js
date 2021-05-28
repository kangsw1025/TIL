function solution(name) {
    var answer = 0;
    var arr = [];
    for(let i = 1;i<name.length;i++)
        if(name[i]!='A') {
            arr.push(i);
        }
    var idx = 0;
    
    while(1) {
        if(arr.length===0) break;
        var left = arr[arr.length-1]>idx ? idx + name.length-arr[arr.length-1] : idx-arr[arr.length-1];
        var right = arr[0] > idx ? arr[0] - idx : name.length - idx + arr[0];
        if(left>=right) {
            answer += right;
            idx = arr.shift();
        }
        else {
            answer += left;
            idx = arr.pop();
        }
    }
    
    for(let i =0;i<name.length;i++)
        answer += Math.min(name.charCodeAt(i)-65 , 91 - name.charCodeAt(i));
    return answer;
}