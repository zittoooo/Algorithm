#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int T, n, err, Rflag;
string p; // 함수
deque<int> dq;

void printRes()
{
    if (!err && !Rflag)
    {
        cout << "[";
        for (int i = 0; i < dq.size(); i++)
        {
            cout << dq[i];
            if (i == dq.size() - 1)
                break;
            cout << ",";
        }
        cout << "]\n";
    }
    else if (!err && Rflag)
    {
        cout << "[";
        for (int i = dq.size() - 1; i >= 0; i--)
        {
            cout << dq[i];
            if (i == 0)
                break;
            cout << ",";
        }
        cout << "]\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char start ,end, comma;
    cin >> T;
    while (T--)
    {
        dq.clear();
        int x;
        cin >> p >> n >> start;
        for (int i = 0; i < n;  i++)
        {
            cin >> x;
            dq.push_back(x);
            if (dq.size() == n)
                break ;
            cin >> comma;
        }
        cin >> end;
        err = 0;
        Rflag = 0;
        for (int i = 0; i < p.length() ; i++)
        {
            //RR 연속으로 나오는 경우
            if (i + 1 < p.length() && p[i] == 'R' && p[i+1] == 'R')
            {
                i++;
                continue ;
            }
            if (p[i] == 'R')
                Rflag = !Rflag;
            else if (p[i] == 'D')
            {
                if (dq.empty())  // 비어있는데 D(버리기)
                {
                    cout << "error\n";
                    err = 1;
                    break ;
                }
                if (Rflag)  // 뒤집혀 있을때 맨뒤 원소 빼기
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        printRes();
    }
}