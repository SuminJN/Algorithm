func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var answer = arr1
    
    for i in 0..<arr1.count {
        for j in 0..<arr1[i].count {
            answer[i][j] += arr2[i][j]
        }
    }
    
    return answer
}