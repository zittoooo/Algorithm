// 연속합
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int input[100001];
int D[100001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];
    D[1] = input[1];
    for (int i = 2; i <= n; i++)
    {
        D[i] = max(D[i-1] + input[i], input[i]);
    }
    cout << *max_element(D+1, D+n+1);
}