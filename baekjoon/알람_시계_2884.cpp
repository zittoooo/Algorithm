#include <iostream>
using namespace std;

int main()
{
	int H, M;

	cin >> H;
	cin >> M;

	if (M < 45)
	{
		if (H == 0)
			H = 23;
		else
			H -= 1;
		M = 60- (45 - M);
	}
	else
	{
		M = M - 45;
	}

	cout << H << ' ' <<  M;
}
