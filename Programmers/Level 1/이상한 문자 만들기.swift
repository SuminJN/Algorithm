func solution(_ s:String) -> String {
    var words = s.components(separatedBy: " ")
    var answer: String = ""
    var temp = 0
    
    for word in words {
        for i in Array(word) {
            if temp % 2 == 0 {
                answer += i.uppercased()
            } else {
                answer += i.lowercased()
            }
            
            temp += 1
        }
        temp = 0
        answer += " "
    }

    return String(answer.dropLast())
}