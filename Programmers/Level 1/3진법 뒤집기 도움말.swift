import Foundation

func solution(_ n:Int) -> Int {
    var N = n
    var arr: [Int] = []
    
    while N != 0 {
        arr.append(N % 3)
        N /= 3
    }
    
    var mul = 1
    var answer = 0
    
    for i in arr.reversed() {
        answer += i * mul
        mul *= 3
    }
    
    return answer
}