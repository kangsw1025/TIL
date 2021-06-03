function solution(s){
    var answer = true;

    var st = [];
    for(let i = 0 ;i<s.length;i++) {
        if(s[i]==='(') st.push('(');
        else {
            if(st.length===0) return false;
            st.pop();
        }
    }
    if(st.length!=0) return false;
    return answer;
}