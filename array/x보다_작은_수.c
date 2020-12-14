#include <stdio.h>

int main()
{
	int size, num;
	int arr[10000];

	scanf("%d %d", &size, &num);
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	for (int i= 0; i < size ;i++)
	{
		if (arr[i] < num)
			printf("%d ", arr[i]);
	}

}
