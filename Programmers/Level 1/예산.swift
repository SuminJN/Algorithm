import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var input = d.sorted()
    var money = budget
    var answer: Int = 0
    
    for i in input {
        if (money - i) < 0 {
            break
        }
        money -= i
        answer += 1
    }
    
    return answer
}