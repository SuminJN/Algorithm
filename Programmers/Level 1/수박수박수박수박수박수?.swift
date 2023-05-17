func solution(_ n:Int) -> String {
    var count = 0
    var answer = ""
    
    while count != n {
        if count % 2 == 0 {
            answer += "수"
        } else {
            answer += "박"
        }
        
        count += 1
    }
    
    return answer
}