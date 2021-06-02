function solution(routes) {
    var answer = 0;
    var cmp = [-40000,-40000];
    
    routes.sort((a,b)=>a[0]-b[0]);
    
    for(let i = 0 ;i<routes.length;i++) {
        var route = routes[i];
        if(route[0]>cmp[1]) {
            answer++;
            cmp = route;
        }
        else {
            cmp[1] = cmp[1] > route[1] ? route[1] : cmp[1];
        }
    }
    
    return answer;
}