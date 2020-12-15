#include <unistd.h>
int not_in_before(char *s, char ch, int len)
{
	int i = 0;
	while (i < len)
	{
		if (s[i] == ch)
			return (0);
		i++;
	}
	return (1);
}

void ft_union(char *s1, char *s2)
{
	int i, j;
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (not_in_before(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (not_in_before(s2, s2[j], j))
		{
			if (not_in_before(s1, s2[j], i))
			{
				write(1, &s2[j], 1);
			}
		}
		j++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
