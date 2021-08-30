#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> dogam1;
map<int, string> dogam2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    string name;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        dogam1.insert({name, i});
        dogam2.insert({i, name});
    }

    string Q;
    map<string, int>::iterator it;
    for (int i = 0; i < M; i++)
    {
        cin >> Q;
        if (dogam1.find(Q) != dogam1.end())
            cout << dogam1[Q] << "\n";
        else
        {
            int val = stoi(Q);
            cout << dogam2[val] << "\n";
        }
    }
    return 0;
}