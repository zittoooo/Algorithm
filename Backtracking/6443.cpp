#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, len, alphabet[26];
string str;
char res[10001];

void word(int depth, int len)
{
    if(depth == len)
    {
        cout << res << "\n";
        return ;
    }
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] > 0)
        {
            alphabet[i]--;
            res[depth] = 'a' + i;
            word(depth+1, len);
            alphabet[i]++;
        }
    }
}

int main()
{
    cin >> n;
    while (n--)
    {
        memset(alphabet, 0, sizeof(alphabet));
        cin >> str;
        len = str.length();
        for(int i = 0; i < len; i++)
            alphabet[str[i] - 'a']++;
        word(0, len);
        
    }
    return 0;
}