func solution(_ n:Int) -> Int {
    var answer = 0
    
    if n == 0 { return 0 }
    
    for i in 1...n {
        if n % i == 0 {
            answer += i
        }
    } 
    
    return answer
}