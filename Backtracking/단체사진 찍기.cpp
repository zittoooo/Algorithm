#include <bits/stdc++.h>
using namespace std;
int selec[8] = {0};
int answer;

void DFS(int depth, vector<char>& Arr, vector<string> data,  char friends[])
{
    if (depth == 8)
    {
        char friend1 = 0, friend2 = 0, op = 0;
        int dist = 0;
        for (int i = 0; i < data.size(); i++)
        {
            friend1 = data[i][0];
            op = data[i][3];
            friend2 = data[i][2];
            dist = data[i][4] - '0';
            dist++;

            int idx = -1, iidx = -1;
            for (int i = 0; i < 8; i++)
            {
                if (Arr[i] == friend1)
                    idx = i;
                if (Arr[i] == friend2)
                    iidx = i;
                if (idx != -1 && iidx != -1) break;
                
            }
            if (op == '=' && abs(idx-iidx) != dist) return;
            if (op == '<' && abs(idx-iidx) >= dist) return;
            if (op == '>' && abs(idx-iidx) <= dist) return;
        }
        
        answer++;
        return;
    }
    
    for (int i = 0; i < 8 ; i++)
    {
        if (selec[i] == 0)
        {
            selec[i] = 1;
            Arr[depth] = friends[i];
            DFS(depth+1, Arr, data, friends);
            selec[i] = 0;
        }
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    selec[8] = {0};
    char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    vector<char>Arr(8);
    DFS(0, Arr, data, friends);  
    
    return answer;
}
