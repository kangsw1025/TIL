function solution(s) {
    var answer = false;
    if(s.length==4 || s.length==6) {
        var check = true;
        for(let i =0;i<s.length;i++) {
            if(!(s[i]>='0' && s[i]<='9')) {
                check = false;
                break;
            }
        }
        if(check) answer = true;
    }
    return answer;
}