#include <iostream>
#include <string>
using namespace std;
int alpa[30] = {-1,};

int main()
{
    string str;
    fill_n(alpa, 30, -1);
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (alpa[str[i] - 'a'] != -1)
            continue ;
        alpa[str[i] - 'a']  = i;
    }

    for (int i = 0; i < 26; i++)
        cout << alpa[i] << " ";
    return 0;
}