function solution(maps) {
    var answer = 0;
    var check = new Array(101);
    for(let i = 0;i<101;i++)
        check[i] = new Array(101).fill(10000);
    
    var q = [];
    var h = maps.length-1;
    var w = maps[0].length-1;
    var n_x = [0,1,0,-1];
    var n_y = [1,0,-1,0];
    q.push([0,0]);
    check[0][0] = 1;
    while(q.length!=0) {
        var now = q.shift();
        var y = now[0];
        var x = now[1];
        var cnt = check[y][x];
        
        if(y==h && x==w) {
            answer = cnt;
            break;
        }
        
        for(let i = 0;i<4;i++) {
            var nx = x + n_x[i];
            var ny = y + n_y[i];
            if(nx>=0 && nx<=w && ny>=0 && ny<=h && maps[ny][nx]) {
                if(cnt +1 < check[ny][nx]) {
                    check[ny][nx] = cnt+1;
                    q.push([ny,nx]);
                }
            } 
        }
        
    }
    if(answer===0) answer = -1;
    return answer;
}