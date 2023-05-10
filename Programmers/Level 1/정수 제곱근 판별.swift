import Foundation

func solution(_ n:Int64) -> Int64 {
    var temp: Int64 = Int64(sqrt(Double(n)))
    var answer: Int64
    
    answer = temp * temp == n ? (temp+1) * (temp+1) : -1
    
    return answer
}