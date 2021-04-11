function solution(seoul) {
    var answer = '';
    var index = seoul.findIndex(s => s=='Kim');
    answer = `김서방은 ${index}에 있다`
    return answer;
}