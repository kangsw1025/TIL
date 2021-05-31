function solution(arr) {
    var answer = [];
    var zero = 0, one = 0;
    
    function sol(x,y,r) {
        if(r==1) {
            if(arr[x][y]=='1') one++;
            else zero++;
        }
        else {
            var same = true;
            var first = arr[x][y];
            for(let i =x;i<x+r;i++)
                for(let j =y;j<y+r;j++)
                    if(arr[i][j]!=first) same = false;
            
            if(same) {
                if(arr[x][y]=='1') one++;
                else zero++;
            }
            else {
                sol(x,y,r/2);
                sol(x+r/2,y,r/2);
                sol(x,y+r/2,r/2);
                sol(x+r/2,y+r/2,r/2);
            }
        }
    }
    sol(0,0,arr.length);
    answer.push(zero,one);
    return answer;
}