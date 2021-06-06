function solution(tickets) {
    var answer = [];
    var rst = [];
    var visit = [];
    tickets.sort();
    
    const len = tickets.length;
    
    const dfs = (city, count) => {
        rst.push(city);
        
        if(count===len) {
            answer = rst;
            return true;
        }
        
        for(let i = 0 ;i<len;i++) {
            if(!visit[i] && tickets[i][0]===city) {
                visit[i] = true;
                if(dfs(tickets[i][1],count+1)) return true;
                visit[i] = false;
            }
        }
        
        rst.pop();
        return false;
    }
    dfs("ICN", 0);
    return answer;
}