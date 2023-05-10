import Foundation

func solution(_ n:Int) -> Int {
    var temp = n
    var answer = 0
    
    while temp > 0 {
        answer += temp % 10
        temp /= 10
    }
    
    return answer
}