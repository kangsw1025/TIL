function solution(citations) {
    var answer = 0;
    var left = 0, right = 10000;
    
    function sol(mid) {
        var cnt = 0;
        for(let i = 0;i<citations.length;i++) {
            if(citations[i]>=mid) cnt++;
            if(cnt>=mid) return true;
        }
            
        return false;
    }
    
    while(left<=right) {
        var mid = Math.floor((left + right) / 2);
        
        if(sol(mid)) {
            if(mid>answer) answer = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return answer;
}