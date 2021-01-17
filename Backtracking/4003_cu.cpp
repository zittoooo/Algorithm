// 네모네모 로직
// https://www.codeup.kr/problem.php?id=4033
#include <iostream>
using namespace std;
int n, k, res;
int flag;  // 칠하면 1, 안 칠하면 0
int input[20];

void    func(int cur, int i, int flag)
{  
	if (cur > n)
		return ;
	if (i == k)
	{
		res++;
		return ;
	}
	if (flag == 0)
		func(cur + input[i], i+1, 1);
	func(cur + 1, i, 0);

}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> input[i];
	func(0, 0, 0);
	cout << res;
}