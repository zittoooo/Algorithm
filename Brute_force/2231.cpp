#include <iostream>
using namespace std;
int N, sum, part;
int cur = 1;

int main()
{
    cin.tie(0);
    cout.sync_with_stdio(0);
    cin >> N;

    for (int i = 1; i < N ; i++)
    {
        sum = i;
        part = i;
        while (part > 0)
        {
            sum += part % 10;
            part /= 10;
        }

        if (N == sum)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}
