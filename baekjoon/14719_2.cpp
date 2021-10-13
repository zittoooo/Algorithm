#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int h, w, res, map[505][505];

int main(){
    cin >> h >> w;
    vector<int> rain(w);
    for (int i = 0; i < w ; i++)
        cin >> rain[i];
    for(int i = 1; i < w - 1; i++)
    {
        int left = 0; int right = 0;
        for (int j = 0; j < i; j++)
            left = max(left, rain[j]);
        for (int j = w-1; j > i ; j--)
            right = max(right, rain[j]);
        res += max(0, min(left, right) - rain[i]);
    }
    cout << res;
}