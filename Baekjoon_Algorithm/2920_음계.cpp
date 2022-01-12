#include <iostream>

using namespace std;
#define MAX 8

bool checkEqualArrays(int* arr1, int* arr2)
{
    for(int i = 0; i < MAX; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }

    return true;
}

int main() 
{
    int asc[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8};
    int des[MAX] = { 8, 7, 6, 5, 4, 3, 2, 1};
    int input[MAX];

    for(int i = 0; i < 8; i++){
        cin >> input[i];
    }
    
    if(checkEqualArrays(asc, input)){
        cout << "ascending";
    } else if(checkEqualArrays(des, input)){
        cout << "descending";
    } else {
        cout << "mixed";
    }
    
    return 0;
}
