#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int first = 0, middle = total / num;
    
    if(num%2 == 0) first = middle - num/2 + 1;
    else first = middle - num/2;
    
    for(int i = 0; i < num; i++) answer.push_back(first++);
    
    return answer;
}