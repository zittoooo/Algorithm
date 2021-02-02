// 연속 부분 최대곱
#include <iostream>
#include <algorithm>
using namespace std;
int n;
double d[10000], arr[10000];  // d[i] i를 포함하는 최대 부분 곱

int main()
{
    cin >> n;
    for (int i = 0 ; i < n; i++)
        cin >> arr[i];
    d[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (d[i-1] * arr[i] > arr[i])
            d[i] = d[i-1] * arr[i];
        else   
            d[i] = arr[i];
    }
    printf("%.3f", *max_element(d, d + n));
}