#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    int N, ticket;
    cin >> N;
    for(int i = 0; i < N ; i++)
    {
        cin >> ticket;
        pq.push(ticket);
    }
    int cur = pq.top(); pq.pop();
    if(cur > 1)
    {
        cout << 1;
        return 0;
    }
    while (cur + 1 == pq.top())
    {
        cur = pq.top();
        pq.pop();
    }
    cout << cur + 1;

    return 0;
}