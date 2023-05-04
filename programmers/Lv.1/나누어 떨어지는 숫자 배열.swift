// Solution 1
func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    var answer: [Int] = []
    
    for num in arr {
        if num % divisor == 0 {
            answer.append(num)
        }
    }
    
    answer.sort()
    
    if answer.count == 0 {
        answer.append(-1)
    }
    
    return answer
}

// Solution 2
// func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
//     let answer = arr.filter{ $0 % divisor == 0 }.sorted()
//     return answer == [] ? [-1] : answer
// }