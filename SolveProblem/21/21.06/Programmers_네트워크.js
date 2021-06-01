function solution(n, computers) {
    var answer = 0;
    var visit = new Array(201).fill(false);
    
    function check(k) {
        for(let i=0;i<n;i++)
            if(visit[i]==false && computers[k][i]==1) {
                visit[i] = true;
                check(i);
            }
        
    }
    
    for(let i =0;i<n;i++)
        if(visit[i]==false) {
            answer++;
            visit[i] = true;
            check(i);
        }
    
    
    return answer;
}