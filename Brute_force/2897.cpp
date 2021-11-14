#include <iostream>
#include <string>
using namespace std;

int R, C;
string map[51];
int res[5], cntX;

int main()
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        cin >> map[i];

    for(int i = 0; i < R-1; i++)
    {
        for(int j = 0; j < C-1; j++)
        {
            cntX = 0;
            if(map[i][j] == '#' || map[i+1][j] == '#' || map[i][j+1] == '#' || map[i+1][j+1] == '#') continue;
            if(map[i][j] == 'X') cntX++;
            if(map[i+1][j] == 'X') cntX++;
            if(map[i][j+1] == 'X') cntX++;
            if(map[i+1][j+1] == 'X') cntX++;
            res[cntX]++;
        }
        
    }
    for(int i = 0; i < 5 ; i++)
        cout << res[i] << "\n";
    return 0;   
}