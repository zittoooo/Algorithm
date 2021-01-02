//하노이 탑 이동 순서
#include <iostream>
using namespace std;

// 원판 n 개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
void    func(int a, int b, int n) 
{
    if (n == 1)
    {
        cout << a << ' ' << b << '\n';
        return ;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
}

int main()
{
    int k;
    cin >> k;
    cout << (1<<k) - 1 << '\n';
    func(1, 3, k);  // k 개의 원판을 기둥 1에서 기둥 3로 옮긴다.
}

/*
7
1 3 
1 2
3 2   
1 3  // n번 원판을 기둥 a에서 기둥 b로 옮긴다.
2 1
2 3
1 3
*/