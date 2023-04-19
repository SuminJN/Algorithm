#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    int arr_size = (my_str.size() % n == 0) ? my_str.size()/n : my_str.size()/n+1;

    vector<string> answer(arr_size, "");

    int temp = 0;

    for(int i = 1; i <= my_str.size(); i++) {
        answer[temp] += my_str[i-1];

        if(i % n == 0) temp++;
    }

    return answer;
}