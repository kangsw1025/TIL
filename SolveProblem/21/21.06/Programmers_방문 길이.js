function move(now,pos) {
    var x = parseInt(now[0]);
    var y = parseInt(now[1]);
    
    if(pos==='U') return [Math.min(5,x+1),y];
    else if(pos==='D') return [Math.max(-5,x-1),y];
    else if(pos==='R') return [x,Math.min(y+1,5)];
    else if(pos==='L') return [x,Math.max(-5,y-1)];
}

function makeroute(now, newplace) {
    return now[0]+','+now[1]+','+newplace[0]+','+newplace[1];
}

function solution(dirs) {
    var answer = 0;
    if(dirs.length===0) return 0;
    
    var route = {};
    var rout = makeroute([0,0],move([0,0],dirs[0]));
    route[rout] = 1;
    answer++;
    for(let i = 1;i<dirs.length;i++) {
        var splited = rout.split(',');
        var now = [splited[2],splited[3]];
        var newplace = move(now,dirs[i]);
        
        if(now[0]==newplace[0] && now[1]==newplace[1]) continue;
        
        rout = makeroute(now,newplace);
        
        if(route[rout] || route[makeroute(newplace,now)]) continue;
        else {
            route[rout] = 1;
            answer++;
        }
    }
    
    return answer;
}