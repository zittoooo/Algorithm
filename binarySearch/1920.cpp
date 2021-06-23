#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M, tmp, mid;
vector<long long> v1;

int main()
{
    cin.tie(NULL);
	ios::sync_with_stdio(0);
    cin >> N;
    while (N--)
    {
        cin >> tmp;
        v1.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    cin >> M;
    while (M--)
    {
        cin >> tmp;
        if (binary_search(v1.begin(), v1.end(), tmp))
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
}
