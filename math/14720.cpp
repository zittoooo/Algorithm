#include<iostream>
#include <stack>
using namespace std;

int main()
{
    int N, milk;
    stack<int> s;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> milk;
        if((s.empty() && milk == 0) || (!s.empty() && s.top() == 2 && milk == 0))
            s.push(milk);            
        if(!s.empty() && milk == s.top()+1)
            s.push(milk);
    }
    cout << s.size();
    return 0;
}