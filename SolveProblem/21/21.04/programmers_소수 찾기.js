function solution(n) {
    var answer = 0;
    let check = new Array(1000001).fill(false);
    check[2] = false;
    for(let i = 2;i<=n;i++) 
        if(!check[i]) 
            for(let j = 2;i*j<=n;j++) check[i*j] = true;
        
    for(let i =2;i<=n;i++) if(!check[i]) answer++;
    return answer;
}