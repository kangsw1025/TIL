function solution(board) {
    var answer = 99999999;
    var q = new Array();
    var n = board.length;
    var n_x = [-1,0,1,0];
    var n_y = [0,1,0,-1];
    var check = new Array(26);
    for(let i = 0;i<26;i++)
        check[i] = new Array(26).fill(false);
    
    var arr = new Array(26);
    for(let i = 0;i<26;i++)
        arr[i] = new Array(26).fill(9999999);
    
    function solve(x,y,value,pos) {
        if(x==n-1 && y==n-1) return;
        
        else {
            for(let i = 0;i<4;i++) {
                var nx = x+n_x[i];
                var ny = y+n_y[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n && !check[nx][ny] && board[nx][ny]==0) {
                    if(pos==-1) {
                        check[nx][ny] = true;
                        arr[nx][ny] = 100;
                        solve(nx,ny,100,i);
                        check[nx][ny] = false;
                    }
                    else {
                        check[nx][ny] = true;
                        if(pos==i) {
                            if(arr[nx][ny]>=value+100) {
                                arr[nx][ny] = value+100;
                                solve(nx,ny,value+100,i);
                            }
                        }
                        else  {
                            if(arr[nx][ny]>=value+600) {
                                arr[nx][ny] = value+600;
                                solve(nx,ny,value+600,i);
                            }
                        }
                        check[nx][ny] = false;
                    }
                }
            }
        }
    }
    arr[0][0] = 0;
    check[0][0] = true;
    solve(0,0,0,-1);
    answer = arr[n-1][n-1];
    return answer;
}