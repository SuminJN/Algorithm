function solution(arr) {
    var sum = 0, answer = 0;
    
    for(let i=0; i<arr.length; i++) {
        sum += arr[i];
    }
    
    answer = sum / arr.length;
    
    return answer;
}