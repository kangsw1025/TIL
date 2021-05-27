function solution(s) {
    var answer = [];
    var list = [];
    var put = [];
    var check = false;
    var num = "";
    var onoff = new Array(100001);
    for(let i = 1;i<s.length-1;i++) {
        if(s[i]==='{') check = true;
        else if(s[i]==='}') {
            check = false;
            put.push(num);
            num = "";
            list.push(put);
            put = new Array();
        }
        else {
            if(check) {
                if(s[i]>='0' && s[i]<='9') num += s[i];
                else if(s[i]===',') {
                    put.push(num);
                    num = "";
                }
            }
        }
    }
    list.sort((a,b)=>a.length-b.length);
    for(let i = 0;i<list.length;i++) {
        var new_list = list[i];
        for(let j = 0;j<new_list.length;j++) {
            var list_num = parseInt(new_list[j]);
            if(onoff[list_num]) continue;
            else {
                answer.push(list_num);
                onoff[list_num] = 1;
                break;
            }
        }
    }
    return answer;
}