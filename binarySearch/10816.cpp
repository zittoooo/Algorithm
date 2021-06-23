#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, tmp;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cin >> M;
    while (M--)
    {
        cin >> tmp;
        vector<int>::iterator lit = lower_bound(v.begin(), v.end(), tmp);
        vector<int>::iterator uit = upper_bound(v.begin(), v.end(), tmp);
        cout << uit - lit << " ";
        
    }
}