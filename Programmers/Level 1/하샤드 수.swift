func solution(_ x:Int) -> Bool {
    var temp = x
    var sum = 0
    
    while temp > 0 {
        sum += temp % 10
        temp /= 10
    }
    
    return x % sum == 0 ? true : false
}