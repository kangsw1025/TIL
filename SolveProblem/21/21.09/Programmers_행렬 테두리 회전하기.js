function solution(rows, columns, queries) {
  var answer = [];
  var arr = new Array(rows);
  for (let i = 0; i < rows; i++) arr[i] = new Array(columns).fill(1);

  for (let i = 0; i < rows; i++)
    for (let j = 0; j < columns; j++) arr[i][j] += i * columns + j;

  for (let i = 0; i < queries.length; i++) {
    var [x1, y1, x2, y2] = queries[i];
    x1--;
    y1--;
    x2--;
    y2--;
    var mn = arr[x1][y1];
    var tmp = mn;

    for (let i = y1 + 1; i <= y2; i++) {
      mn = Math.min(mn, arr[x1][i]);
      var tmp2 = arr[x1][i];
      arr[x1][i] = tmp;
      tmp = tmp2;
    }
    for (let i = x1 + 1; i <= x2; i++) {
      mn = Math.min(mn, arr[i][y2]);
      var tmp2 = arr[i][y2];
      arr[i][y2] = tmp;
      tmp = tmp2;
    }
    for (let i = y2 - 1; i >= y1; i--) {
      mn = Math.min(mn, arr[x2][i]);
      var tmp2 = arr[x2][i];
      arr[x2][i] = tmp;
      tmp = tmp2;
    }
    for (let i = x2 - 1; i >= x1; i--) {
      mn = Math.min(mn, arr[i][y1]);
      var tmp2 = arr[i][y1];
      arr[i][y1] = tmp;
      tmp = tmp2;
    }
    answer.push(mn);
  }

  return answer;
}
