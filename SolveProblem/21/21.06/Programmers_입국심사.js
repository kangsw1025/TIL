function solution(n, times) {
    var answer = 0;
    var left = 1, right = 9e12;
    
    function check(mid) {
        var cnt = 0;
        for(let i = 0 ; i<times.length;i++) {
            cnt += parseInt(mid/times[i]);
            if(cnt>=n) break;
        }
        return cnt>=n ? true : false;
    }
    
    while(left<=right) {
        var mid = parseInt((left+right)/2);
        if(check(mid)) right = mid - 1;
        else left = mid + 1;
    }
    answer = left;
    return answer;
}