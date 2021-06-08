function solution(n, s) {
    var answer = [];
    if(s<n) return [-1];
    
    var num = parseInt(s/n);
    var left = s%n;
    var arr1 = new Array(n-left).fill(num);
    var arr2 = new Array(left).fill(num+1);
    answer = [...arr1, ...arr2];
    return answer;
}