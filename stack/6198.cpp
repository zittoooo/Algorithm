#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int N, h;
long long res;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> h;
        while (!s.empty() && s.top() <= h)
            s.pop();
        s.push(h);
        res += s.size()-1;
    }
    cout << res;
    return 0;
}
