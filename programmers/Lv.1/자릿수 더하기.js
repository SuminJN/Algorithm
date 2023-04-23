function solution(n)
{
    var input = String(n);
    var answer = 0;

    for(let i=0; i<input.length; i++) {
        answer += Number(input[i]);
    }

    return answer;
}