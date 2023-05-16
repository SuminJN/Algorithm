func solution(_ s:String) -> String {
    var arr = Array(s)
    var answer = ""
    
    if arr.count % 2 == 0 {
        answer = answer + String(arr[arr.count/2 - 1]) + String(arr[arr.count/2])
    } else {
        answer += String(arr[arr.count/2])
    }
    
    return answer
}