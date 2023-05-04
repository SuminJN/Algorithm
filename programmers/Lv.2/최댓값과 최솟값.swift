func solution(_ s:String) -> String {
    var arr: [Int] = s.components(separatedBy: " ").map{ Int($0)! }
    arr.sort()
    
    return String(arr[0]) + " " + String(arr[arr.count-1])
}