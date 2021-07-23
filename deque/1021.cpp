#include <deque>
#include <iostream>

using namespace std;
int N, M, x, idx, cnt;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    cin >> M;
    while (M--)
    {
        cin >> x;
        for (int i = 0; i< dq.size(); i++)
        {
            if (dq[i] == x)
            {
                idx = i;
                break;
            }
        }
        if (idx <= dq.size()/2)
        {
            while (1)
            {
                if (dq.front() == x)
                {
                    dq.pop_front();
                    break ;
                }
                else
                    ++cnt;
                    dq.push_back(dq.front());
                    dq.pop_front();
            }
        }
        else
        {
            while (1)
            {
                if (dq.front() == x)
                {
                    dq.pop_front();
                    break ;
                }
                else
                {
                    ++cnt;
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
        }
    }
    cout << cnt;
}

/*
8 9 10

1 6 3 2 7 9 8 4 10 5
0,5,3,0,0,1
*/