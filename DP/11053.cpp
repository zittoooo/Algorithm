// 가장 긴 증가하는 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1005];   // 1000하면 컴파일 에러
int D[1005];   // 1000하면 컴파일 에러 

int main()
{
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> a[i];
    D[0] = 1;
    for (int i = 1; i < n ; i++)
    {
        D[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                D[i] = max(D[i], D[j] + 1); 
            }
        }
    }
    cout << *max_element(D, D+n);
}


/*
수열 A의 크기 N (1 ≤ n ≤ 1,000)

수열 A를 이루고 있는 Ai (1 ≤ ai ≤ 1,000)
*/