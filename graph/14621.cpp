#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int parent[10002];
typedef struct {
    int parent;
    int MW;
} parentMW;

typedef struct {
    int x;
    int y;
    int weight;
} tmp;
vector<tmp> wei;
vector<parentMW> parents;
bool chk;
int res, cnt;

bool cmp (tmp wei1, tmp wei2)
{
    if (wei1.weight < wei2.weight)
		return 1;
	return 0;
}

int find(int dot)
{
    if (dot == parents[dot].parent)
        return dot;
    return parents[dot].parent = find(parents[dot].parent);
}

void merge(int start, int end)
{
	chk = false;
    if (parents[start-1].MW == parents[end-1].MW)
        return ;
	start = find(start);
	end = find(end);
	
	if (start == end)
		return ;
	parents[start].parent = parents[end].parent;
	chk = true;
}

int main(void)
{
    int v, e, a, b, c;
    char ch;

	cin >> v >> e;
	for (int i = 0; i < v; i++){ // 부모를 자기 자신으로 초기화
		cin >> ch;
        if (ch == 'M')
            parents.push_back({i, 1});
        else
            parents.push_back({i, 2});
    }
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
        wei.push_back({a, b, c});
	}
    sort(wei.begin(), wei.end(), cmp);
	for (int i = 0; i < e; i++)
	{
		merge(wei[i].x, wei[i].y);
		if (chk)
        {
            cnt++;
			res += wei[i].weight;
        }
	}
    if (cnt != v-1){
        cout << -1;
        return 0;
    }
	cout << res;
	return 0;
}