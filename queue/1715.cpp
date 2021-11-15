#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
long long res, A, B;

int main()
{
    int N = 0, card = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> card;
        pq.push(card);
    }
    while (pq.size() >= 2)
    {
        A = pq.top();
        pq.pop();

        B = pq.top();
        pq.pop();

        res += (A + B);
        if(!pq.empty())
            pq.push(A+B);
    }
    cout << res;
    return 0;
}