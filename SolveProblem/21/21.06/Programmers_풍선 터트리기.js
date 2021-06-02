function solution(a) {
    var answer = 0;
    var left = new Array(1000001).fill(0);
    var right = new Array(1000001).fill(0);
    
    var small;
    
    for(let i = 0 ;i<a.length;i++) {
        if(i==0) small = a[i];
        else {
            if(a[i]>small) left[i] = 1;
            else small = a[i];
        }
    }
    for(let i = a.length-1 ;i>=0;i--) {
        if(i==a.length-1) small = a[i];
        else {
            if(a[i]>small) right[i] = 1;
            else small = a[i];
        }
    }
    for(let i = 0 ;i<a.length;i++) {
        if(left[i] == 1 && right[i]==1) continue;
        else answer++;
    }
    return answer;
}