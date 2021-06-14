/*
< : 오름차순
> : 내림차순
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int n;

bool compare(pair<int, int>&a, pair<int,int>&b)
{
    if (a.Y == b.Y)
        return a.X < b.X;
    else
        return a.Y < b.Y;
}

int main()
{
    cin >> n;
    pair<int ,int > cur;
    vector<pair<int, int> > v;
    while (n--)
    {
        cin >> cur.X >> cur.Y;
        v.push_back(cur);
    }
    sort(v.begin(), v.end(), compare);
    for (vector<pair<int, int> >::iterator i = v.begin(); i != v.end(); i++)
        cout << i->X << " " << i->Y << "\n";
}