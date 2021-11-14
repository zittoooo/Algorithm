#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int num[10];

int main()
{
    cin >> N;
    while(N)
    {
        if(N%10 != 9)
            num[N%10]++;
        if(N%10 == 9)
            num[6]++;
        N /= 10;
    }
    num[6] = ceil((double)num[6]/2);
    cout << *max_element(num, num+10);
    return 0;
}