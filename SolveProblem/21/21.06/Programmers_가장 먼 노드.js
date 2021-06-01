function solution(n, edge) {
    var answer = 0;
    var dst = new Array(20001).fill(-1);
    var vec = new Array(20001);
    var q = new Array();
    var Max = 0;
    for(let i = 0;i<20001;i++)
        vec[i] = new Array();
    dst[1] = 0;
    for(let i = 0;i<edge.length;i++) {
        let u = edge[i][0];
        let v = edge[i][1];
        
        vec[u].push(v);
        vec[v].push(u);
    }
    
    q.push(1);
    while(1) {
        if(q.length===0) break;
        var now = q.shift();
        
        for(let i = 0;i<vec[now].length;i++) {
            var next = vec[now][i];
            
            if(dst[next]==-1) {
                dst[next] = dst[now]+1;
                q.push(next);
            }
            else {
                if(dst[next] > dst[now]+1) {
                    dst[next] = dst[now] + 1;
                    q.push(next);
                }
            }
            Max = Math.max(Max,dst[next]);
        }
    }
    
    for(let i = 1;i<=n;i++) if(dst[i]===Max) answer++;
    
    return answer;
}