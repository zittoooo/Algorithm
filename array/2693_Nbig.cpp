#include <iostream>
#include <algorithm>
using namespace std;
int arr[11];

bool	compare(int a, int b)
{
	return a > b;
}

int main()
{
	int n;

	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 10; i++)
			cin >> arr[i];
		sort(arr, arr+ 10, compare);
		cout << arr[2] << '\n';
	}
	return (0);
}