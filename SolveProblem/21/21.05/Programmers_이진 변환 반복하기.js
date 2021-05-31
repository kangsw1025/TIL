

function solution(s) {
    var answer = [];
    var zero = 0;
    var change = 0;
    
    function tentotwo(n) {
        n = parseInt(n);
        var num = '';
        while(1) {
            if(n===0) break;
            if(n%2===0) num = '0' + num;
            else if(n%2===1) {
                n--;
                num = '1' + num;
            }
            n/=2;
        }
        return num;
    }
    
    while(1) {
        if(s==='1') break;
        var new_s = 0;
        for(let i = 0;i<s.length;i++) {
            if(s[i]==='0') zero++;
            else new_s++;
        }
        s = tentotwo(new_s);
        change++;
    }
    answer.push(change);
    answer.push(zero);
    return answer;
}