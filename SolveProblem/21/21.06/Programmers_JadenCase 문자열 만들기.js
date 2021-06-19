function solution(s) {
    var answer = '';
    var arr = s.split(' ');
    for(let i =0;i<arr.length;i++) {
        var word = arr[i].split('');
        if(word[0]>='a' && word[0]<='z') {
            word[0] = word[0].toUpperCase();
        }
        for(let j = 1;j<word.length;j++)
            if(word[j]>='A' && word[j]<='Z') word[j] = word[j].toLowerCase();
        arr[i] = word.join('');        
    }
    answer = arr.join(' ');
    return answer;
}