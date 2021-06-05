function solution(clothes) {
    var answer = 1;
    var obj = [];
    var job = [];
    for(let i = 0;i<clothes.length;i++) {
        if(obj[clothes[i][1]])  obj[clothes[i][1]]++;
        else {
            job.push(clothes[i][1]);
            obj[clothes[i][1]] = 2; 
        }
    }
    for(let i = 0;i< job.length;i++)
        answer *= obj[job[i]];    
    
    return answer-1;
}