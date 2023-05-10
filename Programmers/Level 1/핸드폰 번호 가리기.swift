func solution(_ phone_number:String) -> String {
    var answer = ""
    var arr = Array(phone_number)
    
    for _ in 0..<phone_number.count-4 {
        answer += "*"
    }
    
    for i in arr.count-4..<arr.count {
        answer.append(arr[i])
    }
    
    return answer
}