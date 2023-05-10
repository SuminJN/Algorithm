import Foundation

func solution(_ numbers:[Int]) -> Int {
    var answer = 45
    
    for i in  numbers {
        answer -= i
    }

    return answer
}