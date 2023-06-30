import Foundation

func solution(_ s:String) -> Int {
    let number: Dictionary<String, String> = ["zero": "0", "one": "1", "two": "2", "three": "3", "four": "4", "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"]
    
    var answer: String = ""
    var temp: String = ""
    
    for i in s.indices {
        if s[i] >= "0" && s[i] <= "9" {
            answer.append(s[i])
        } else {
            temp.append(s[i])
            if number[temp] != nil {
                answer.append(number[temp]!)
                temp = ""
            }
        }
    }
    
    return Int(answer)! 
}