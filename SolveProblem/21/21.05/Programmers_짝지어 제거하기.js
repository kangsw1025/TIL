function solve(s) {
    let i = 0;
     let stack = [];
     let string = s.split('');
     
     while(i<s.length) {
         if(stack.length===0) stack.push(s[i]);
         else stack[stack.length-1]===s[i] ? stack.pop() : stack.push(s[i]);
         i++;
     }
     
     return stack.length===0 ? true : false;
 }
 
 function solution(s)
 {
     var answer = 0;
     
     if(s.length%2===1) return 0;
     return solve(s) ? 1 : 0;
 }