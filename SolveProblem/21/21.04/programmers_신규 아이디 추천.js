function solution(new_id) {
    var answer = '';
    let first = new_id.toLowerCase();
    console.log(first);
    let second = '';
    for(let i =0;i<first.length;i++) 
        if((first[i]>='a' && first[i]<='z') || (first[i]>='0' && first[i]<='9') || first[i] == '-' || first[i]=='_' || first[i]=='.') second += first[i];
    console.log(second);
    
    let third = '';
    let check = false;
    for(let i = 0;i<second.length;i++) {
        if(second[i]=='.') check = true;
        else {
            if(check) third += '.';
            check = false;
            third += second[i];
        }
    }
    if(check) third += '.';
    console.log(third)
    if(third[0]=='.') third = third.slice(1,third.length);
    if(third[third.length-1]=='.') third = third.slice(0,third.length-1);
    let fourth = third;
    console.log(fourth);
    let fifth = '';
    if(!fourth) fifth = 'a';
    else fifth = fourth;
    console.log(fifth);

    let sixth = fifth;
    if(sixth.length>=16) sixth = sixth.slice(0,15);
    if(sixth[sixth.length-1]=='.') sixth = sixth.slice(0,sixth.length-1);
    console.log(sixth, sixth.length)
    let seventh = sixth;
    if(seventh.length<=2)
        while(seventh.length<3) seventh += seventh[seventh.length-1];
    answer = seventh;
    return answer;
}