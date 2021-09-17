#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, C, x;
int arr[200001];
vector<int> house;

int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        house.push_back(x);
    }
    sort(house.begin(), house.end());

    int shortest = 1;
    int longest = house[N-1] - house[0];
    int result = 0;

    while (shortest <= longest)
    {
        int mid = (shortest + longest) / 2;
        int cnt = 1;
        int pre_install_house = house[0];

        for (int i = 1; i < N; i++)
        {
            if (house[i] - pre_install_house >= mid)
            {
                cnt++;
                pre_install_house = house[i];
            }
        }

        if (cnt >= C)
        {
            result = max(result, mid);
            shortest = mid + 1;
        }
        else
            longest = mid - 1;
    }
    cout << result;
    return(0);
}

// c이상 설치가 가능하다면
// start = mid+1;
// c이상 설치가 불가능하다면
// end = mid-1;
// 이런 식으로 값의 범위를 좁혀가고
// c이상 설치가 가능할 때의 mid값들 중 최대값을 출력하면 된다.

