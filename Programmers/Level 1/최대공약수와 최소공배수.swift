func solution(_ n:Int, _ m:Int) -> [Int] {    
    return [gcd(n, m), lcm(n, m)]
}

func gcd(_ a: Int, _ b: Int) -> Int {
    var A = a
    var B = b
    var temp: Int
    
    while B != 0 {
        temp = A % B
        A = B
        B = temp
    }
    
    return A
}

func lcm(_ a: Int, _ b: Int) -> Int {
    return (a * b) / gcd(a, b)
}