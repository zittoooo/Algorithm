#include <iostream>
#include <vector>
using namespace std;

/*
1. vector의 front 값의 인덱스를 출력 후 삭제
2. front 값의 움직일 수가 양수이면 (움직일 수 - 1)만큼 다음 front 값들을 뒤로 보냄
3. front 값의 움직일 수가 음수이면 그 수만큼 back 값들을 앞으로 보냄
4. vector가 빌 때까지 1, 2, 3 반복
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int , int>> v;
	int N;
	int num;
	int i= 1;

	cin >> N;
	while (N--)
	{
		cin >> num;
		v.push_back({i++, num});
	}
	while (!v.empty())
	{
		cout << v.front().first << ' ';
		num = v.front().second;
		v.erase(v.begin());
		if (num > 0)
		{
			for (int i = 0;i < num - 1;i++)
			{
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
		else
		{
			for (int i = 0; i < -num; i++)
			{
				v.insert(v.begin(), v.back());
				v.pop_back();
			}
		}
	}

}

