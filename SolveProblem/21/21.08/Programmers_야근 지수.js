function solution(n, works) {
  if (works.reduce((a, b) => a + b) <= n) return 0;

  let work = works.sort((a, b) => a - b);
  const len = work.length;

  while (n) {
    const max = work[len - 1];
    for (let i = len - 1; i >= 0; i--) {
      if (work[i] >= max) {
        work[i]--;
        n--;
      }
      if (!n) break;
    }
  }

  return work.reduce((acc, n) => acc + Math.pow(n, 2), 0);
}
