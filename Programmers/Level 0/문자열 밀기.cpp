#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int size = A.size(), count = 0;
    string temp = "";
    bool flag = false;
    
    if(A.compare(B) == 0){
        return 0;
    }
    
    for(int i = 0; i < size; i++) {
        count++;
        
        temp = A[size-1] + A.substr(0, size-1);
        A = temp;
        
        if(A.compare(B) == 0){
            flag = true;
            break;
        }
    }
    
    if(flag) return count;
    else return -1;
}