function solution(n, words) {
    var answer = [];
    var use = [];
    var wrong = false;
    let i;
    use[words[0]] = 1;
    for(i = 1;i<words.length;i++) {
        var word = words[i];
        if(word[0]===words[i-1][words[i-1].length-1]) {
            if(!use[word]) use[word] = 1;
            else {
                wrong = true;
                break;
            }
        }
        else {
            wrong = true;
            break;
        }
    }
    
    if(!wrong) answer.push(0,0);
    else answer.push((i%n) + 1, Math.ceil((i+1)/n));
    return answer;
}