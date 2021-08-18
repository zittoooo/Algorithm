#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
bool alpa[26];

int main()
{
    int n, cnt=0;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str.length() >= 2)
        {
            memset(alpa,0,sizeof(alpa));
            for (int i = 0; i < str.length() - 1; i++)
            {
                alpa[str[i] - 'a'] = true;
                if (alpa[str[i + 1] - 'a'] && str[i] != str[i + 1])
                {
                    cnt++;
                    break ;
                }
            }
        }
    }
    cout << n - cnt;
}