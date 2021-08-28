#include <iostream>
#include <map>

using namespace std;
map<string, bool, greater<string> > nameState;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string name, state;
    map<string, bool, greater<string> >::iterator it;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> state;
        if (state.compare("enter") == 0)
            nameState.insert({name, true});
        else if (state.compare("leave") == 0)
        {
            nameState.erase(nameState.find(name));
        }
    }
    map<string, bool, greater<string> >::iterator iter;
    for (iter = nameState.begin(); iter != nameState.end(); iter++)
            cout << iter->first << "\n";
}