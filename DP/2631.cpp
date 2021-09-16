#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int input;
int lis[205];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        if (arr.empty() || arr.back() < input)
        {
            arr.push_back(input);
        }
        else
        {
            *lower_bound(arr.begin(), arr.end(), input) = input;
        }

    }
    cout << N - arr.size();
    return 0;
}