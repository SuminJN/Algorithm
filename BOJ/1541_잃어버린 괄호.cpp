#include <iostream>
#include <string>
using namespace std;

int len, temp_num, answer;
string str, temp_str;
bool flag = false;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    len = str.size();

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == '-' || str[i] == '+' || i == len)
        {
            if (flag == false)
            {
                answer += stoi(temp_str);
                temp_str = "";
            }
            else
            {
                answer -= stoi(temp_str);
                temp_str = "";
            }

            if (str[i] == '-')
            {
                flag = true;
            }
        }
        else
        {
            temp_str += str[i];
        }
    }

    cout << answer;

    return 0;
}