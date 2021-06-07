function solution(N, number) {
    var answer = 0;
    var arr = [new Set()];
    for(let i = 1;i<=8;i++) {
        arr.push(new Set([new Array(i).fill(N).join('') * 1]));
        for(let j = 1;j<=i;j++) {
            for(const x1 of arr[j]) {
                for(const x2 of arr[i-j]) {
                    arr[i].add(x1+x2);
                    arr[i].add(x1-x2);
                    arr[i].add(x1*x2);
                    if(x2) arr[i].add((x1/x2) - (x1/x2)%1);
                }
            }
        }
        if(arr[i].has(number)) return i;
    }
    return -1;
}