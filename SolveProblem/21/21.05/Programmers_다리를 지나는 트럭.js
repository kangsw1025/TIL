function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    var bridge = [];
    var now = 0;
    var idx = 0;
    var front = 0;
    var time;
    for(time = 0;time>=0;time++) {
        if(bridge.length>0)
            if(time-bridge[0]===bridge_length) {
                now -= truck_weights[front++];
                bridge.shift();
                if(front===truck_weights.length) break;
            }
        
        if(now + truck_weights[idx]<=weight) {
            bridge.push(time);
            now += truck_weights[idx++];
        }
    }
    answer = time + 1;
    return answer;
}