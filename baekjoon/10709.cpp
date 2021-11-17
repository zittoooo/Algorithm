#include<iostream>
#include<string>
using namespace std;
int h, w;
string map[101];
int rain[101][101];

int main()
{
    cin >> h >> w;
    for(int i = 0; i < h; i++)
    {
        cin >> map[i];
        for(int j = 0; j < w; j++)
        {
            if(map[i][j] == '.')
                rain[i][j] = -1;
            if(map[i][j] == 'c')
                rain[i][j] = 0;
        }
    }
    for (int j = 0; j < w; j++)
    {
        for(int i = 0; i < h; i++)
        {
            if(rain[i][j+1] != 0 && map[i][j] == 'c' && j+1 < w)
            {
                rain[i][j+1] = rain[i][j] + 1;
                map[i][j+1] = 'c';
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
        {
            cout << rain[i][j] << " "; 
        }
        cout << "\n";
    }
    return 0;
}