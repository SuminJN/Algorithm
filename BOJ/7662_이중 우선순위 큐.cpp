#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;

    cin >> T;

    while (T--)
    {
        cin >> N;

        char c;
        int num;
        multiset<int> ms;

        while (N--)
        {
            cin >> c >> num;

            if (c == 'I')
            {
                ms.insert(num);
            }
            else
            {
                if (!ms.empty() && num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
                else if (!ms.empty() && num == -1)
                {
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty())
        {
            cout << "EMPTY" << "\n";
        }
        else
        {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << "\n";
        }
    }

    return 0;
}