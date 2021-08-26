#include <iostream>
#include <string>
#include <set>

using namespace std;
set<string> s;

int main()
{
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 1; j <= input.length(); j++)
        {
            s.insert(input.substr(i,j));
        }
    }
    cout << s.size();
}