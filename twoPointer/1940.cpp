#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, tmp, res;
vector<int> v;

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int i = 0, j = v.size()-1;
    while (i < j)
    {
        if (v[i] + v[j] == M)
        {
            i++;
            j--;
            res++;
        }
        else if (v[i] + v[j] < M)
            i++;
        else
            j--;
    }
    cout << res;
}