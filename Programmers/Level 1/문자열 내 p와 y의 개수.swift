import Foundation

func solution(_ s:String) -> Bool {
    var ans:Bool = false
    var str = s.lowercased()
    var count: (Int, Int) = (0, 0)
    
    for i in str {
        if i == "p" {
            count.0 += 1
        } else if i == "y" {
            count.1 += 1
        }
    }
    
    ans = count.0 == count.1 ? true : false
    
    return ans
}