#include <iostream>
#include <algorithm>
using namespace std;
int arr[5], tmp;
bool isSwap = false;

int main()
{
    for(int i = 0; i < 5; i++)
        cin >> arr[i];
    while (1)
    {
        isSwap = false;
        for (int i = 0, j = 1; j < 5; i++, j++)
        {
            if(arr[i] > arr[j])
            {
                isSwap = true;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                for(int i = 0; i < 5; i++)
                    cout << arr[i] << " ";
                cout << "\n";
            }
        }
        if(isSwap == false)
            break;
    }
    return 0;
}