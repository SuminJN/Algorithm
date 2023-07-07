func solution(_ a:Int, _ b:Int) -> String {
    let week = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED", ]
    let monthDay = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    var totalDay = b
    
    for i in monthDay[0..<a-1] {
        totalDay += i
    }
    
    print(totalDay)
    
    return week[totalDay % 7]
}