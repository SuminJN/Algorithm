func solution(_ arr:[Int]) -> [Int] {
    var answer = arr
    var min = Int.max
    var target = 0
    
    for i in 0..<arr.count {
        if min > arr[i] {
            min = arr[i]
            target = i
        }
    }
    
    answer.remove(at: target)
    
    return answer.isEmpty ? [-1] : answer
}