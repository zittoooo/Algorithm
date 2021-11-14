#include<iostream>
#include<string>
using namespace std;

int main()
{
    char alpa;
    string str;
    int cnt = 0;

    while (1)
    {
        cnt = 0;
        cin >> alpa;
        if (alpa == '#')
            return 0;
        cin.ignore();
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == alpa || str[i] == alpa - 32)
                cnt++;
        }
        cout << alpa << " " << cnt << "\n";
    }
    return 0;
}