#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > v1;
int K, vec, len;
long long res, w, h, sw, sh;


int main()
{
    cin >> K;
    for (int i = 0; i < 6 ; i++)
    {
        cin >> vec >> len;
        v1.push_back({vec, len});
    }
    for (int i = 0; i < 6 ; i++)
    {
        if (i%2 == 0)
        {
            if (h < v1[i].second)
                h = v1[i].second;
        }
        else
        {
            if (w < v1[i].second)
                w = v1[i].second;
        }
    }
    for (int i = 0; i < 6 ; i++)
    {
        if (i%2 == 0)
        {
            if (w == v1[(i+5) % 6].second + v1[(i+1) % 6].second)
                sh = v1[i].second;
        }
        else
        {
            if (h == v1[(i+5) % 6].second + v1[(i+1) % 6].second)
                sw = v1[i].second;
        }
    }
    // cout << h << " " << w << " " << sh << " " << sw << "\n"; 
    res = ((w * h) - (sh * sw));
    cout << K * res;
}