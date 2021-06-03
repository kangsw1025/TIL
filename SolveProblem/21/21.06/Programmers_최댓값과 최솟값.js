function solution(s) {
    var answer = '';
    var arr = s.split(' ');
    arr.sort((a,b) => parseInt(a)-parseInt(b));
    answer = arr[0] + ' ' + arr[arr.length-1];
    return answer;
}