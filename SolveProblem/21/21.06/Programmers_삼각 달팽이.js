function solution(n) {
    var answer = [];
    var Max = n*(n+1)/2;
    var arr = new Array(Max).fill(0);
    arr[0] = 1;
    var idx = 0, add = 1, cnt = 2;
    while(1) {
        while(idx+add<Max && arr[idx+add]===0 && cnt <= Max) {
            arr[idx+add] = cnt++;
            idx += add;
            add++;
        }
        while(idx+1 <Max && arr[idx+1]===0 && cnt<=Max) {
            arr[++idx] = cnt++;
        }
        while(idx-add >=0 && arr[idx-add]===0 && cnt <=Max) {
            arr[idx-add] = cnt++;
            idx -= add;
            add--;
        }
        if(cnt===Max+1) break;
    }
    answer = arr;
    return answer;
}