
function solution(n)
{
    var ans = 0;
    
    while(1) {
        if(n==0) break;
        if(n%2===1) {
            ans++;
            n--;
        }
        if(n%2===0) n/=2;
    }
    
    return ans;
}