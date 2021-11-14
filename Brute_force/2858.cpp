#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int R, B, L, W;
    cin >> R >> B;

    int sum = R + B;
    L =  R / 2 - 1;
    while(1)
    {
        if(sum % L == 0)
        {
            W = sum / L;
            if((L-2) * (W-2) == B)
                break;
        }
        L--;
    }
    if(L > W)
        cout << L << " " << W;
    else
        cout << W << " " << L;
    return 0;
}