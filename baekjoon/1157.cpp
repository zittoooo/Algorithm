#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int d[26];
int main()
{
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z') // 대문자
            d[input[i] - 'A'] += 1;
        else
            d[input[i] - 'a'] += 1;
    }
    int mx = 0;
    for (int i = 0; i < 26; i++)    //가장 큰 값 찾기
        mx = max(mx, d[i]);     

    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < 26; i++)
    {
        if (mx == d[i])
        {
            cnt++;
            idx = i;
        }
    }
    if (cnt > 1)
    {
        cout << "?";
        return 0;
    }
    cout << char(idx+65);
}