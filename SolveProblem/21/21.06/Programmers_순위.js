function solution(n, results) {
    var answer = 0;
    var arr = new Array(101)
    for(let i = 0;i<101;i++) 
        arr[i] = new Array(101).fill(0);
    
    for(let i = 0;i<results.length;i++) {
        var winner = results[i][0];
        var loser = results[i][1];
        
        arr[winner][loser] = 1;
    }
    
    for(let k = 1 ;k<=n;k++) 
        for(let i = 1;i<=n;i++) {
            if(k==i) continue;
            for(let j = 1;j<=n;j++) {
                if(i==j) continue;
                if(arr[i][k]===1 && arr[k][j]===1) {
                    arr[i][j] = 1;
                }
            }
        }
    
    for(let i =1;i<=n;i++) {
        var cnt = 0;
        for(let j =1;j<=n;j++) 
            if(arr[i][j]===1 || arr[j][i]===1) cnt++;
        if(cnt===n-1) answer++;
    }
    
    return answer;
}