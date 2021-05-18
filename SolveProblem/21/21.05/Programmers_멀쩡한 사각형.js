function solution(w, h) {
    var answer = w*h;
    if(w==h) answer -= w;
    else {
        var gcd = 1;
        for(var i = w<h ? w:h;i>0;i--) {
            if(w%i==0 && h%i==0) {
                gcd = i;
                break;
            }
        }
        answer -= (Math.ceil(w/gcd) + Math.ceil(h/gcd) - 1) * gcd;
    }
    return answer;
}