function solution(gems) {
    var answer = [1, 100000];
    
    let gemlen = new Set(gems).size;
    let gemMap = new Map();
    
    for(let i = 0 ;i<gems.length;i++) {
        gemMap.delete(gems[i]);
        gemMap.set(gems[i],i+1);
        
        if(gemMap.size===gemlen) {
            var cmp = [gemMap.values().next().value, i+1];
            answer = (answer[1]-answer[0]) > (cmp[1]-cmp[0]) ? [cmp[0],cmp[1]] : [answer[0],answer[1]];
        }
    }
    return answer;
}