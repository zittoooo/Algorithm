#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct kruskal {
    int x;
    int y;
    int val;
} tmp;

vector<tmp> edge;

int parent[10002];
int res;
bool chk;

bool comp(tmp d1, tmp d2)
{
    return d1.val < d2.val;
}

int find(int dot)
{
    if(dot == parent[dot]) // dot의 부모가 dot 자기자신이면
        return dot;
    return parent[dot] = find(parent[dot]);
}

void merge(int x, int y)
{
    chk = false;
    x = find(x);
    y = find(y);
    if(x == y)
        return ;
    parent[x] = y;
    chk = true;
}

int main()
{
    int v, e, a, b, c;
    cin >> v >> e;
    for(int i = 0; i < v; i++) // 부모를 자기자신으로 초기화
        parent[i] = i;
    
    for(int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edge.push_back({a,b,c});
    }
    sort(edge.begin(), edge.end(), comp);
    for(int i = 0 ; i < e ; i++)
    {
        merge(edge[i].x, edge[i].y);
        if(chk)
            res += edge[i].val;
    }
    cout << res;
    return 0;
}