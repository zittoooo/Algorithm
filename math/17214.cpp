#include <iostream>
#include <string>
using namespace std;
string input, op = "", cur = "", sign = "";

int main()
{
    int xx = 0, x = 0, i = 0;

    cin >> input;
    if (input[0] == '-')
    {
        sign = "-";
        i++;
    }
    while (input[i])
    {
        if (input[i] >= '0' && input[i] <= '9')
            cur += input[i];
        if (input[i] == 'x')
        {
            xx = stoi(cur) / 2;
            cur.clear();
        }
        if (input[i] == '+' || input[i] == '-')
            op = input[i];
        i++;
    }
    if (!cur.empty())
        x = stoi(cur);
    //출력
    if (xx != 0)
    {
        if (sign.compare("-") == 0)
        {
            cout << sign;
            sign.clear();
        }
        
        if (xx != 1)
            cout << xx << "xx";
        else
            cout << "xx";
    }
    if (!op.empty())
        cout << op;
    if (x != 0)
    {
        if (sign.compare("-") == 0)
            cout << sign;
        if (x != 1)
            cout << x << "x";
        else 
            cout << "x";
    }
    if (xx == 0 && x == 0)
        cout << "W";
    else
        cout << "+W";
    return 0;
}