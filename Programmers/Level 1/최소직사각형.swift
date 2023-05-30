import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var input = sizes
    var row = 0
    var col = 0
    var temp = 0
    var answer = 0
    
    for i in 0..<input.count {
        if input[i][0] < input[i][1] {
            temp = input[i][0]
            input[i][0] = input[i][1]
            input[i][1] = temp
        }
        
        if input[i][0] > row {
            row = input[i][0]
        }
        
        if input[i][1] > col {
            col = input[i][1]
        }
    }
    
    answer = row * col
    
    return answer
}