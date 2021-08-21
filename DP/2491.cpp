#include <iostream>
#include <algorithm>
using namespace std;
int arr[100002];
int asc[100002];
int desc[100002];

int main()
{
    int n, mx1 = 0, mx2 = 0;
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> arr[i];
    asc[0] = 1;
    desc[0] = 1;

    for (int i = 1; i < n ; i++)
    {
        if (arr[i] >= arr[i-1])
            asc[i] = asc[i-1] + 1;
        else
            asc[i] = 1;
        if (arr[i] <= arr[i-1])
            desc[i] = desc[i-1] + 1;
        else
            desc[i] = 1;
    }
    for (int i = 0; i < n ; i++)
        mx1 = max(mx1, asc[i]);
    for (int j = 0; j < n ; j++)
        mx2 = max(mx2, desc[j]);
    cout << max(mx1, mx2);
}