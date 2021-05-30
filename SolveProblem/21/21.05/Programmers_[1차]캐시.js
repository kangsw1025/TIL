function solution(cacheSize, cities) {
  var answer = 0;
  var cache = [];
  var q = [];
  if (cacheSize == 0) {
    answer = cities.length * 5;
  } else {
    for (let i = 0; i < cities.length; i++) {
      var city = cities[i].toLowerCase();
      if (cache[city] == 1) {
        answer++;
        var idx = q.findIndex((n) => n === city);
        q.splice(idx, 1);
        q.push(city);
      } else {
        cache[city] = 1;
        answer += 5;
        if (q.length == cacheSize) {
          var erase = q.shift();
          cache[erase] = 0;
        }
        q.push(city);
      }
    }
  }
  return answer;
}
