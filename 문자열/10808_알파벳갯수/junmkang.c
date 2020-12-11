nclude <iostream>

using namespace std;

int		main(void)
{	
	string	s;
	int		a[30];
	
	for(int i = 0; i < 30; i++)
		a[i] = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++)
		cout << a[i] << " "; 
	
	return (0);
}
