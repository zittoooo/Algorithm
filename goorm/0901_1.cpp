#include <iostream>
using namespace std;
bool team[88];
int main()
{
	int input_team;
	int	my_team;
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> input_team;
		team[input_team] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		cin >> my_team;
		if (team[my_team] == 0)
			cnt++;
	}
	cout << cnt;
	return (0);
}