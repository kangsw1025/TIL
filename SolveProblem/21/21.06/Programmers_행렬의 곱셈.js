function solution(arr1, arr2) {
    var answer = [];
        
    for(let i = 0 ;i<arr1.length;i++) {
        var arr = new Array();
        for(let j = 0;j<arr2[0].length;j++) {
            var num = 0;
            for(let k = 0 ;k<arr1[i].length;k++) {
                num += (arr1[i][k]*arr2[k][j]);
            }
            arr.push(num);
        }
            
        answer.push(arr);
    }
    
    return answer;
}