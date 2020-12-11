#include <stdio.h>

int main(void)
{
	char str[100];
	char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' ,'l', 'm' ,'n' ,'o' ,'p'
	,'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int count[26] = {0};
	int i;
	int j;

	scanf("%s", str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == alpha[j])
		{
			count[j]++;
			j = 0;
			i++;
		}
		else
			j++;
	}
	for (i = 0; i < 26; i++)
	{
		printf("%d ", count[i]);
	}
	return (0);
}
