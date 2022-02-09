#include <iostream>

using namespace std;

int row, col, R;
int arr[300][300];

void Rotate(int x1, int y1, int x2, int y2)
{
    int temp = arr[x1][y1];

    for(int i = y1; i < y2; i++) arr[x1][i] = arr[x1][i+1];
    for(int i = x1; i < x2; i++) arr[i][y2] = arr[i+1][y2];
    for(int i = y2; i > y1; i--) arr[x2][i] = arr[x2][i-1];
    for(int i = x2; i > x1; i--) arr[i][y1] = arr[i-1][y1];

    arr[x1+1][y1] = temp;
}

void Rotate()
{
    int x1 = 0, y1 = 0, x2 = row - 1, y2 = col - 1;

    while(x1 < x2 && y1 < y2)
    {
        for(int i = 0; i < (R % ((x2-x1 + y2-y1) * 2)); i++){
            Rotate(x1, y1, x2, y2);
        }

        x1++; y1++; x2--; y2--;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col >> R;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    Rotate();

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
