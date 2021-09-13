#include <iostream>
#include <string>
using namespace std;

string input;
int res = 0;
bool isMinus = false;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> input;

    string cur;
    int num = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '-' || input[i] == '+')
        {
            num = stoi(cur);
            cur.clear();
            if (!isMinus)
                res += num;
            else
                res -= num;
            if (input[i] == '-')
                isMinus = true;
        }
        else
            cur += input[i];
    }
    num = stoi(cur);
    if (!isMinus)
        res += num;
    else
        res -= num;
    cout << res;
}