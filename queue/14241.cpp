#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main()
{
    int n, tmp, res = 0;
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        cin >> tmp;
        pq.push(tmp);
    }
    while (pq.size() >= 2)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        res += x * y;
        int z = x + y;
        pq.push(z);
    }
    cout << res;
}