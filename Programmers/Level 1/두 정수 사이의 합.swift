// Solution 1
func solution(_ a:Int, _ b:Int) -> Int64 {
    var flag: Bool = true
    
    if abs(a) > abs(b) && a < 0 && b >= 0 {
        flag = false
    } else if abs(a) < abs(b) && a >= 0 && b < 0 { 
        flag = false
    } else if a < 0 && b < 0 {
        flag = false
    } else {
        flag = true
    }

    let middle: Double = abs((Double(a) + Double(b)) / 2)
    let count = abs(a - b) + 1
    var answer: Int64 = (flag == true) ? Int64(middle * Double(count)) : -Int64(middle * Double(count))
    
    return answer
}


// Solution 2
// func solution(_ a:Int, _ b:Int) -> Int64 {
//     return Int64(Array(a > b ? b...a : a...b).reduce(0, +))
//   }