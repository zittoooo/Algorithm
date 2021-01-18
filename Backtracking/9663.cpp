// N-Queen
#include <iostream>
using namespace std;
int N, cnt;
bool isused1[40];
bool isused2[40];
bool isused3[40];

void    func(int cur)  // cur번째 행에 말을 배치할 예정
{
	if (cur == N)
	{
		cnt++;
		return ;
	}
	for (int i = 0; i < N; i++)
	{
		if (isused1[i] || isused2[cur+i] || isused3[cur-i+N-1])
			continue ;
		isused1[i] = 1;
		isused2[cur+i] = 1;
		isused3[cur-i+N-1] = 1;
		func(cur+1);
		isused1[i] = 0;
		isused2[cur+i] = 0;
		isused3[cur-i+N-1] = 0;
	}

}

int main()
{
	cin >> N;
	func(0);
	cout << cnt;
}