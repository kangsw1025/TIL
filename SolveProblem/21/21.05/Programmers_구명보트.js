function solution(people, limit) {
    var answer = 0;
    people.sort((a,b) => a-b);
    while(1) {
        if(people.length==0) break;
        answer++;
        var num = people.pop();
        if(people.length>=1) {
            if(num + people[0]<=limit) people.shift();    
        }
    }
    return answer;
}