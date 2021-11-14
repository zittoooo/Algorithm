#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<int> v;
int tmp;

int main()
{
    int cnt = 0;
    for(int i = 0; i < 5; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < INT_MAX ; i++)
    {
        cnt = 0;
        for(int j = 0; j < 5; j++)
        {
            if(i % v[j] == 0)
                cnt++;
            if(cnt == 3)
            {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}