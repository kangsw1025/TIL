function solution(n, costs) {
    var answer = 0;
    var vec = new Array(101);
    var check = new Array(101).fill(false);
    var q = [];
    for(let i = 0;i<101;i++)
        vec[i] = new Array();

    for(let i = 0;i<costs.length;i++) {
        var u = costs[i][0];
        var v = costs[i][1];
        var p = costs[i][2];
        vec[u].push([p,v]);
        vec[v].push([p,u]);
    }
    check[0] = true;
    
    for(let i = 0;i<vec[0].length;i++)
        q.push(vec[0][i]);
    q.sort((a,b)=>a[0]-b[0]);
    
    while(q.length!=0) {
        var arr = q.shift();
        var next = arr[1];
        var pay = arr[0];
        if(check[next]==false) {
            check[next] = true;
            answer += pay;
            for(let i = 0 ;i<vec[next].length;i++)
                q.push(vec[next][i]);
            q.sort((a,b)=>a[0]-b[0]);
        }
    }
    return answer;
}