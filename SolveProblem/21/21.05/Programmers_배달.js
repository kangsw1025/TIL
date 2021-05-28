function solution(N, road, K) {
    var answer = 0;
    var ans = new Array(N + 1).fill(1000000);
    var arr = new Array(N+1);
    for(let i =0;i<N+1;i++) 
        arr[i] = new Array(N+1).fill(1000000);
    
    for(let i = 0;i<road.length;i++) {
        var v = road[i][0];
        var u = road[i][1];
        var dst = road[i][2];
        arr[v][u] = Math.min(arr[v][u],dst);
        arr[u][v] = Math.min(arr[u][v],dst);
    }
    
    var q = [];
    ans[1] = 0;
    q.push(1);
    while(q.length!==0) {
        var now = q.shift();
        for(let i = 1;i<N+1;i++) {
            var next = arr[now][i];
            if(next!=1000000)
                if(ans[i] > ans[now] + next) {
                    ans[i] = ans[now] + next;
                    q.push(i);
                }
        }
        
    }
    for(let i =1;i<=N;i++) {
        if(ans[i]<=K) answer++;
    }
    
    return answer;
}