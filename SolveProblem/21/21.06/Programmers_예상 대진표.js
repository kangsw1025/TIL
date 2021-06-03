function solution(n,a,b)
{
    var answer = 0;
    if(a>b) {
        var arr = new Array(a,b);
        a = arr[1];
        b = arr[0];
    }
    while(1) {
        answer++;
        if(a%2==1) a++;
        if(b%2==1) b++;
        if(a==b) break;
        a /= 2;
        b /= 2;
    }

    return answer;
}