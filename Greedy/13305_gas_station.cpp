// 주유소
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long>distance(n);
    priority_queue<long long, vector<long long>, greater<long long> > cost;  // 벡터를 이용하여 우선순위 큐를 생성 => 최소힙
    for (int i = 0; i < n - 1; i++)
        cin >> distance[i];
    long long answer = 0;
    for (int i = 0 ; i < n ; i++)
    {
        long long x;
        cin >> x;
        cost.push(x);
        answer += cost.top() * distance[i];
    }
    cout << answer;
}

/*
std::priority_queue는 우선순위 큐라고도 불리는데, 내부적으로 힙(Heap)과 비슷하게 동작한다. 
따라서 최대힙 또는 최소힙이 필요할 때 해당 컨테이너를 사용할 수 있다.

root에 가장 작은 값이 존재하는 최소힙을 원하면 미리 정의된 std::greater<>를 넣어주면 된다. (오름차순)
*/