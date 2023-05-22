func solution(_ s:String) -> Bool {

    if s.count != 4 && s.count != 6 {
        return false
    }
    
    for i in Array(s) {
        if i.isNumber == false {
            return false
        }
    }
    
    return true
}