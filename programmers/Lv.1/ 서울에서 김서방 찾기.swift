func solution(_ seoul:[String]) -> String {
    var temp = 0;
    
    for i in 0..<seoul.count {
        if(seoul[i] == "Kim") { temp = i; }
    }
    
    return "김서방은 \(temp)에 있다"
}