#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int N, k;
int res[1000005];
stack<int> s;
stack<int> backup;

int main()
{
    memset(res, -1, sizeof(res));
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> k;
        s.push(k);
    }
    backup.push(s.top());
    s.pop();
    for (int i = N-2; i >= 0; i--)
    {
        if(s.empty() || backup.empty())
            break;
        if (s.top() < backup.top())
        {
            res[i] = backup.top();
            backup.push(s.top());
        }
        else
        {
            backup.pop();
            while (!backup.empty())
            {
                if (s.top() < backup.top())
                {
                    res[i] = backup.top();
                    backup.push(s.top());
                    break;
                }
                else
                {
                    res[i] = -1;
                    backup.pop();
                }
            }
            if (backup.empty())
            {
                res[i] = -1;
                backup.push(s.top());
            }
        }
        s.pop();
    }
    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
    return (0);
}