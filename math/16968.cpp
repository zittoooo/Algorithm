// 차량 번호판
#include <iostream>
using namespace std;
string a;
long long res = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        char prev;
        if (i == 0)
            prev = '\0';
        else
            prev = a[i - 1];
        int n;
        if (a[i] == 'd')
            n = 10;
        else
            n = 26;
        if (prev == a[i])
            n--;
        res *= n;
    }
    cout << res;
}