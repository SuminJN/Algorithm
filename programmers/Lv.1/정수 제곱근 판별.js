function solution(n) {
    let temp = Math.sqrt(n);
    
    return Number.isInteger(temp) ? Math.pow(temp+1, 2) : -1;
}