import Foundation

func solution(_ t:String, _ p:String) -> Int {
    var str = t
    var num = Int(p)!
    var len = p.count
    var arr = [Int]()
    var answer = 0
    
    for i in 0 ... t.count-len {
        let startIdx = str.index(str.startIndex, offsetBy: i)
        let endIdx = str.index(str.startIndex, offsetBy: i+len)
        var sliced_str = str[startIdx ..< endIdx]
        
        if Int(sliced_str)! <= num {
            answer += 1
        }
    }
    
    return answer
}