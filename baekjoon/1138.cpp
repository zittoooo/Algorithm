#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> res;

int main()
{
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = N; i > 0 ; i--)
    {
        if (res.size() == 0 || v[i-1] >= res.size())
            res.push_back(i);
        else
            res.insert(res.begin() + v[i-1], i);
    }
    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
}