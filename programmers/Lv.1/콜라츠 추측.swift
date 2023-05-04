func solution(_ num:Int) -> Int {
    var count = 0
    var temp = num
    
    while(temp != 1 && count < 500) {
        if temp % 2 == 0 {
            temp /= 2
            count += 1
        } else {
            temp = temp * 3 + 1
            count += 1
        }
    }
    
    return temp == 1 ? count : -1
}