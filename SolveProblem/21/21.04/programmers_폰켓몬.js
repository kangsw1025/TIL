function solution(nums) {
    var answer = 0;
    let cnt = 0;
    nums.sort((a,b)=>a-b);
    let now = -1;
    for(let i = 0;i<nums.length;i++) 
        if(now != nums[i]) {
            cnt ++;
            now = nums[i];
        }
    answer = Math.min(cnt,nums.length/2);
    return answer;
}