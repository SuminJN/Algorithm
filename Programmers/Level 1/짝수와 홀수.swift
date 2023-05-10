func solution(_ num:Int) -> String {
    var answer: String
    var temp = num
    
    if temp % 2 == 0 {
        answer = "Even"
    } else {
        answer = "Odd"
    }
    
    return answer
}