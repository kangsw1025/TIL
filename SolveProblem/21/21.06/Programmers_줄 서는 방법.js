function fact(n) {
    var rst = 1;
    for(let i =2;i<=n;i++) rst *= i;
    return rst;
}

function solution(n, k) {
    var answer = [];
    var use = new Array(21).fill(false);
    
    var fac = fact(n);
    
    function find_num(cnt) {
        var id = 0;
        for(let i = 1;i<=n;i++) {
            if(use[i]===false) {
                id++;
                if(id===cnt) {
                    use[i] = true;
                    return i;
                }
            }
        }
    }
    var complete = true;
    for(let i = n ;i>=1;i--) {
        fac = fac / i;
        var cnt = Math.ceil(k/fac);
        answer.push(find_num(cnt));
        k = k%fac;
        if(k===0) {
            for(let i = n;i>=1;i--)
                if(use[i]===false) answer.push(i);
            break;
        }
    }
    
    return answer;
}