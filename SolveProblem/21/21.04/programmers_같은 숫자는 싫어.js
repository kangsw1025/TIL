function solution(arr)
{
    var answer = [];
    let now = -1;
    for(let i = 0;i<arr.length;i++) 
        if(arr[i]!=now) {
            answer.push(arr[i]);
            now = arr[i];
        }
    return answer;
}