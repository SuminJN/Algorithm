#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{   
    vector<int> v;
    int temp;

    cin >> temp;
    v.push_back(temp);

    cin >> temp;
    v.push_back(temp);

    cin >> temp;
    v.push_back(temp);

    sort(v.begin(), v.end());

    for(int i = 0; i < 3; i ++){
        cout << v[i] << " ";
    }

    
        
    return 0;
}