#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int N, x, y;
vector<pair<int ,int> > v;
queue<int> Q;

int main()
{
    cin >> N;
    while (N--)
    {
        cin >> x >> y;
        v.push_back({x,y});
    }

    for (int i = 0; i < v.size(); i++)
    {
        int rank = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i].first < v[j].first && v[i].second < v[j].second)
                rank++;
        }
        cout << rank << " ";
    }
}