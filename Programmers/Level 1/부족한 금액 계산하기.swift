import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    var answer:Int64 = -Int64(money)
    
    for i in 1...count {
        answer += Int64(price * i)
    }
    
    return answer <= 0 ? 0 : answer
}