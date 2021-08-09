function solution(n) {
  var answer = 0;

  function possible(board, row) {
    for (let i = 1; i < row; i++) {
      if (board[i] == board[row]) return false;
      if (Math.abs(board[i] - board[row]) == Math.abs(i - row)) return false;
    }
    return true;
  }

  function solve(board, row) {
    if (row == n) answer++;
    else {
      for (let i = 1; i <= n; i++) {
        board[row + 1] = i;
        if (possible(board, row + 1)) solve(board, row + 1);
      }
    }
  }

  for (let i = 1; i <= n; i++) {
    let board = new Array(n + 1).fill(0);
    board[1] = i;
    solve(board, 1);
  }

  return answer;
}
