function solution(board, moves) {
    var answer = 0;
    let basket = new Array();
    for(let i = 0;i<moves.length;i++) {
        const move = moves[i]-1;
        for(let j = 0;j<board.length;j++) {
            if(board[j][move]) {
                if(board[j][move]==basket[basket.length-1]) {
                    answer += 2;
                    basket.pop();
                }
                else {
                    basket.push(board[j][move]); 
                }
                board[j][move] = 0;
                break;
            }
        }
    }
    
    return answer;
}