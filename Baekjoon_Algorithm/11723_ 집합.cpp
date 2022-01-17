#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int M;
    string commend;
    int value, bit = 0;

    cin >> M;

    while(M--){
        cin >> commend;

        if(commend == "add"){
            cin >> value;
            bit |= (1 << value);
        }
        else if(commend == "remove"){
            cin >> value;
            bit &= ~(1 << value);
        }
        else if(commend == "check"){
            cin >> value;
            if(bit & (1 << value)){
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
        else if(commend == "toggle"){
            cin >> value;
            bit ^= (1 << value);
        }
        else if(commend == "all"){
            bit = (1 << 21) - 1;
        }
        else if(commend == "empty"){
            bit = 0;
        }
    }

    return 0;
}
