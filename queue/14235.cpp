#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main()
{
    int n = 0, a = 0, present;
    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a == 0)
        {
            if(!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "-1\n";
        }
        else
        {
            for (int i = 0; i < a; i++)
            {
                cin >> present;
                pq.push(present);
            }
        }
    }
    return 0;
}