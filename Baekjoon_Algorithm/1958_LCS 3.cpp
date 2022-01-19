#include <iostream>

using namespace std;

int lcs[101][101][101];

int main()
{   
    string str1;
    string str2;
    string str3;

    cin >> str1;
    cin >> str2;
    cin >> str3;

    str1 = '0' + str1;
    str2 = '0' + str2;
    str3 = '0' + str3;

    int len1 = str1.size();
    int len2 = str2.size();
    int len3 = str3.size();

    for(int i = 1; i < len1; i++){
        for(int j = 1; j < len2; j++){
            for(int k = 1; k < len3; k++){
                if(str1[i] == str2[j] && str2[j] == str3[k]){
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                } 
                else{
                    if(lcs[i-1][j][k] > lcs[i][j-1][k] || lcs[i-1][j][k] > lcs[i][j][k-1])
                        lcs[i][j][k] = lcs[i-1][j][k];
                    else if(lcs[i][j-1][k] > lcs[i-1][j][k] || lcs[i][j-1][k] > lcs[i][j][k-1])
                        lcs[i][j][k] = lcs[i][j-1][k];
                    else
                        lcs[i][j][k] = lcs[i][j][k-1];
                }
            }
        }
    }

    cout << lcs[len1 - 1][len2 - 1][len3 - 1];

    return 0;
}
