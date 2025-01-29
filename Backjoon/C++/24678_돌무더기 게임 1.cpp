#include <iostream>

using namespace std;

int x, y, z;

bool check()
{
	int cnt = 0;

	if(x % 2 == 0) cnt++;
	if(y % 2 == 0) cnt++;
	if(z % 2 == 0) cnt++;

	if(cnt > 1) return true;
	else return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while(T--)
	{	
		cin >> x >> y >> z;

		if(check()){
			cout << "R\n";
		}
		else{
			cout << "B\n";
		}
	}

    return 0;
}
