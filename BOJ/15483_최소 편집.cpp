#include <iostream>

using namespace std;

int lcs[1001][1001];

int main()
{   
    string str1;
    string str2;

    cin >> str1;
    cin >> str2;

    str1 = '0' + str1;
    str2 = '0' + str2;

    int len1 = str1.size();
    int len2 = str2.size();

    for(int i = 0; i < len1; i++){
        lcs[i][0] = i;
    }

    for(int i = 0; i < len2; i++){
        lcs[0][i] = i;
    }

    for(int i = 1; i < len1; i++){
        for(int j = 1; j < len2; j++){
            if(str1[i] == str2[j]){
                lcs[i][j] = lcs[i-1][j-1];
            } 
            else{
                lcs[i][j] = min(lcs[i-1][j], min(lcs[i][j-1], lcs[i-1][j-1])) + 1;
            }
        }
    }

    cout << lcs[len1 - 1][len2 - 1];

    return 0;
}
