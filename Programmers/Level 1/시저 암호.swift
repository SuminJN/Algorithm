func solution(_ s:String, _ n:Int) -> String {
    var answer = ""
    
    for value in s.utf16 {
        var temp = value + UInt16(n)
        
        if value >= 65 && value <= 90 {
            if temp > 90 {
                temp -= 26
            }
        } else if value >= 97 && value <= 122 {
            if temp > 122 {
                temp -= 26
            }
        } else {
            temp -= UInt16(n)
        }
        
        answer += "\(UnicodeScalar(temp)!)"
    }
    
    return answer
}