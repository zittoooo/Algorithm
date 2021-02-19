// 회의실배정
#include <iostream>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int N;
pair <int ,int > p[100000];

int main()
{
    int count = 0;
    int t = 0;
    cin >> N;
    for (int i = 0; i < N ; i++)
        cin >> p[i].Y >> p[i].X;
    sort(p, p + N);
    for (int i = 0; i < N; i++)
    {
        if (t > p[i].Y) continue;
        count++;
        t = p[i].X;
    }
    cout << count;
}