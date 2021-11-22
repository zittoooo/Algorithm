#include <iostream>
#include <queue>
using namespace std;
int n, map[1001];

int main()
{
    map[1] = 1;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        if(map[i] == 0)
            break ;
        
        for(int j = 1; j <= num; j++)
        {
            if(i + j > 1000)
                break ;
            if(map[i + j] > map[i] + 1 || map[i+j] == 0)
                map[i+j] = map[i] + 1;
        }
    }

    if(map[n] == 0)
        cout << "-1";
    else
        cout << map[n]-1;
    
    return 0;
}