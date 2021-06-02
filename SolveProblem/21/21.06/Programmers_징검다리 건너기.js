function solution(stones, k) {
    var answer = 0;
    var left = 1, right = 2000000000;
    
    function check(mid) {
        var cnt = 0;
        for(let i = 0;i<stones.length;i++) {
            if(stones[i]<mid) {
                cnt++
                if(cnt>=k) return false;
            }
            else cnt = 0;
        }
        return true;
    }
    
    while(left<=right) {
        var mid = Math.floor((left+right)/2);
        if(check(mid)) {
            left = mid + 1;
            if (answer < mid) answer = mid;
        }
        else right = mid-1;
    }
    return answer;
}