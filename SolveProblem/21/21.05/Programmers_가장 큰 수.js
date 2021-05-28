function solve(a, b) {
    a = a.toString();
    b = b.toString();
    var a_len = a.length;
    var b_len = b.length;
    
    for(let i =0;i<a_len * b_len;i++) {
        if(a[i%a_len] === b[i%b_len]) continue;
        else return b[i%b_len]-a[i%a_len];
    }
    return 1;
}

function solution(numbers) {
    var answer = '';
    numbers.sort((a,b)=>solve(a,b));
    numbers.forEach(n=>answer+=n);
    if(parseInt(answer)===0) answer = "0";
    return answer;
}