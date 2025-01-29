#include <iostream> 
#include <stack>

using namespace std;

int main() {
    
    while(1){
        string str;
        bool flag = true;
        stack<char> s;
        getline(cin, str);

        if(str.length() == 1 && str[0] == '.')
            break;

        for(int i=0; i<str.length(); i++){
            if(str[i] == '(' || str[i] == '[')
                s.push(str[i]);

            if(str[i] == ')'){
                if(s.empty() || s.top() == '[')
                    flag = false;
                else
                    s.pop();
            }

            if(str[i] == ']'){
                if(s.empty() || s.top() == '(')
                    flag = false;
                else
                    s.pop();
            }
        }

        if(flag == true && s.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
