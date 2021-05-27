function solution(priorities, location) {
    var print = priorities;
    var answer = 0;
    var important = new Array(10).fill(0);
    var list = [];
    
    function is(num) {
        if(num==9) return true;
        else {
            for(let i = num+1;i<=9;i++) if(important[i]>0) return false;
            return true;
        }
    }
    
    for(let i = 0;i<print.length;i++) {
        important[print[i]]++;
        list.push([print[i],i]);
    }
    
    while(1) {
        var array = list.shift();
        if(is(array[0])) {
            answer++;
            if(array[1]==location) break;
            important[array[0]]--;
        }
        else list.push(array);
    }
    return answer;
}