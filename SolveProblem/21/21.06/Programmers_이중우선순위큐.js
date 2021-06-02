function solution(operations) {
    var answer = [];
    var q = [];
    for(let i = 0;i<operations.length;i++) {
        var arr = operations[i];
        var op = arr[0];
        var num = "";
        for(let i =2;i<arr.length;i++) num += arr[i];
        if(op==='I') {
            q.push(parseInt(num));
            q.sort((a,b)=>a-b);
        }
        else {
            if(num=="1") q.pop();
            else q.shift();
        }
    }
    if(q.length==0) answer.push(0,0);
    else answer.push(q[q.length-1],q[0]);
    return answer;
}