import Foundation

func solution(_ left:Int, _ right:Int) -> Int {
    var answer = 0
    
    for i in left...right {
        if numOfDivs(i) % 2 == 0 {
            answer += i
        } else {
            answer -= i
        }
    }
    
    return answer
}

func numOfDivs(_ target: Int) -> Int {
    var cnt = 0
    var i = 1
    
    while i*i <= target {
        if target % i == 0 {
            cnt += 2
            if i*i == target { cnt -= 1}
        }
        
        i += 1
    }
    
    return cnt
}