func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer = [String]()
    var arr = [Int]()
    
    for i in arr1.indices {
        arr.append(arr1[i] | arr2[i])
    }
    
    arr = arr.map {
        Int(String($0, radix: 2))!
    }
    
    for i in arr.indices {
        answer.append(String(arr[i]))
        
        if answer[i].count != n { 
            for _ in 0..<n-answer[i].count {
                answer[i].insert("0", at: answer[i].index(answer[i].startIndex, offsetBy: 0))
            }
        }
        
        answer[i] = answer[i].replacingOccurrences(of: "1", with: "#")
        answer[i] = answer[i].replacingOccurrences(of: "0", with: " ")
    }

    return answer
}