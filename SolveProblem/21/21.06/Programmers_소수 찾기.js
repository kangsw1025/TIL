var sosu = new Array(10000000).fill(true);
var used = new Array(10000000).fill(false);
var use = new Array(7).fill(false);

function sol(num,s) {
    var sum = 0;
    var Int = parseInt(num);
    if(used[Int]==false) {
        used[Int] = true;
        if(sosu[Int]) sum++;
    }
    for(let i = 0;i<s.length;i++) {
        if(use[i]==false) {
            use[i] = true;
            sum += sol(num + s[i],s);
            use[i] = false;
        }
    }
    return sum;
}

function solution(numbers) {
    var answer = 0;
    var arr = numbers.split('');
    var mySet = new Set();
    sosu[0] = false;
    sosu[1] = false;
    for(let i = 2;i<5000000;i++)
    if(sosu[i]) 
        for(let j = 2;i*j<10000000;j++)
            sosu[i*j] = false;
    
    
    for(let i = 0;i<arr.length;i++) {
            use[i] = true;
            answer += sol(arr[i],arr);
            use[i] = false;
    }
    return answer;
}