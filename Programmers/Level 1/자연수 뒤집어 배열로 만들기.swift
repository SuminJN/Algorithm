func solution(_ n:Int64) -> [Int] {
    var answer: [Int] = []
    var temp = Int(n)
    
    while temp > 0 {
        arr.append(temp % 10)
        temp /= 10
    }
    
    return answer
}