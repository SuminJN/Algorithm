import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var arr = array
    var answer = [Int]()
    
    for command in commands {
        var temp = [Int]()
        for i in (command[0]-1)...(command[1]-1) {
            temp.append(arr[i])
        }
        temp.sort()
        answer.append(temp[command[2]-1])
    }
    
    return answer
}


/*
import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    return commands.map({ command in 
        return array[(command[0]-1)...(command[1]-1)].sorted()[command[2]-1]
    })
}
/*