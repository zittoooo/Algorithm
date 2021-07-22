#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
vector<pair<int,int> > v;

template <typename T1, typename T2>
class compare
{
    public:
    bool operator()(const pair<T1, T2>&a, const pair<T1, T2>&b)
    {
        return a.second > b.second;
    }
};

priority_queue<pair<int,int>, vector<pair<int, int> >, compare<int, int> > pq;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    v.reserve(N);
    while (N--)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (pq.empty())
            pq.push(v[i]);
        else
        {
            pq.push(v[i]);
            if (pq.top().second <= v[i].first)  //끝나는 시간 <= 시작 시간
                pq.pop();
        }
    }
    cout << pq.size();
}

/*
0 40
15 30
5 10
20 35
35 50

0 40
5 10
15 30
20 35
35 50

pq : {35 50} {0 40} {20 35} {15 30} 

*/