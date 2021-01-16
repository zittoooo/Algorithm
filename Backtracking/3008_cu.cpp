// 일곱 난쟁이
#include <iostream>
#include <algorithm>
using namespace std;
int short_man[9];
int arr[9];

void    func(int cur, int tot, int man)
{
    if (cur == 9)
    {
        if (man == 7 && tot == 100)
        {
            sort(arr, arr+7);
            for (int i = 0; i < 7; i++)
                printf("%d\n", arr[i]);
            exit(0);
        }
        return ;
    }
    arr[man] = short_man[cur];
    func(cur+1, tot+short_man[cur], man+1);
    func(cur+1, tot, man);
}

int main()
{
    for (int i = 0; i < 9; i++)
        cin >> short_man[i];
    func(0, 0, 0);
}