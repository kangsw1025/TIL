function spin(word) {
    var newword = word.substring(1,word.length);
    return newword+word[0];
}

function isright(word) {
    var st = [];
    for(let i = 0 ; i<word.length;i++) {
        if(word[i]==='[' || word[i]==='(' || word[i]==='{') st.push(word[i]);
        else {
            if(st.length===0) return false;
            else {
                if(word[i]===']') {
                    if(st.pop()!='[') return false;
                }
                else if(word[i]===')') {
                    if(st.pop()!='(') return false;
                }
                else if(word[i]==='}') {
                    if(st.pop()!='{') return false;
                }
            }
        }
    }
    if(st.length!=0) return false;
    return true;
}

function solution(s) {
    var answer = 0;
    var word = s.slice();
    for(let i = 0 ; i<s.length;i++) {
        word = spin(word);
        if(isright(word)) answer++;
    }
        
    return answer;
}