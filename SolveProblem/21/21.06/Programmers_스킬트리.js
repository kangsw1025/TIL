function solution(skill, skill_trees) {
    var answer = 0;
    var can = new Array(26).fill(true);
    var idx = 0;
    for(let i = 0;i<skill.length;i++)
        can[skill.charCodeAt(i)-65] = false;
    for(let i =0;i<skill_trees.length;i++) {
        idx = 0;
        var sp = skill_trees[i];
        var learn = true;
        for(let j =0;j<sp.length;j++) {
            if(can[sp.charCodeAt(j)-65]===false) {
                if(sp[j]===skill[idx]) idx++;
                else {
                    learn = false;
                    break;
                }
            }
        }
        if(learn) answer++;
    }
    return answer;
}