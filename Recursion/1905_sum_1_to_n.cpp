#include <iostream>
using namespace std;
int n, res;

void    func(int k)
{
    if (k == 0) return ;
    res += k;
    func(k -1);
}

int main()
{
    cin >> n;
    func(n);
    cout << res;
}