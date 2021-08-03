/*가장 긴 증가하는 부분 수열 O(N log N) */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int a;
    vector<int> arr;

    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int input;
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
    cout << arr.size();
}