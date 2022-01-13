#include <iostream>

using namespace std;

int board[9][9];

bool check(int num, int n)
{
    int row = num / 9;
    int col = num % 9;

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == n)
            return false;
        if (board[i][col] == n)
            return false;
    }

    for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++)
    {
        for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++)
        {
            if (board[i][j] == n)
                return false;
        }
    }

    return true;
}

void solve(int num)
{
    int row = num / 9;
    int col = num % 9;

    if (num == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    if (board[row][col] != 0)
    {
        solve(num + 1);
        return;
    }

    // BackTracking
    for (int i = 1; i <= 9; i++)
    {
        if (check(num, i))
        {
            board[row][col] = i;
            solve(num + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(0);

    return 0;
}
