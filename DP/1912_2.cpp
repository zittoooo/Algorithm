#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;
int d[100005];
int cons = 1;

int main()
{
	int tmp;
	
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    d[0] = v[0];
    // cout << d[0] << " ";
    for (int i = 1; i < n ; i++)
    {
        if (v[i] >= d[i-1] + v[i])
            d[i] = v[i];
        else
            d[i] = d[i-1] + v[i];
        // cout << d[i] << " ";
    }
    cout << *max_element(d, d+n);
}