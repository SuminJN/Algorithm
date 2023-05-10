import Foundation

func solution(_ my_string:String, _ overwrite_string:String, _ s:Int) -> String {
    var myChars = Array(my_string)
    var overChars = Array(overwrite_string)
    
    for i in 0..<overChars.count {
        myChars[s + i] = overChars[i]
    }
    
    let answer = String(myChars)
    
    return answer 
}