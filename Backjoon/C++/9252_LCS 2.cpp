#include <iostream>
#include <stack>

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

    for(int i = 1; i < len1; i++){
        for(int j = 1; j < len2; j++){
            if(str1[i] == str2[j]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } 
            else{
                if(lcs[i-1][j] > lcs[i][j-1])
                    lcs[i][j] = lcs[i-1][j];
                else
                    lcs[i][j] = lcs[i][j-1];
            }
        }
    }

    int i = len1 - 1;
    int j = len2 - 1;
    stack<char> st;

    while(lcs[i][j] != 0){
        if(lcs[i][j] == lcs[i-1][j]){
            i--;
        }
        else if(lcs[i][j] == lcs[i][j-1]){
            j--;
        }
        else{
            st.push(str1[i]);
            i--;
            j--;
        }
    }

    cout << lcs[len1 - 1][len2 - 1] << "\n";

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }

    return 0;
}
