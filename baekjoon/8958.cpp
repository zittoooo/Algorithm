#include <iostream>
using namespace std;
int N, sum, tmp;
string str;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {   
        cin >> str;
        sum = 0;
        tmp = 1;
        for (int i = 0 ; i < str.length(); i++)
        {
            if (str[i] == 'O')
            {
                sum += tmp;
                tmp++;
            }
            else
            {
                tmp = 1;
            }
        }
        cout << sum << "\n";
    }
}