#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int N, arr[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int ,int> m;   
    cin >> N;
    for (int i = 0; i < N ; i++)
    {
        cin >> arr[i];
        m.insert({arr[i], i});
    }
    int i = 0;
    map<int ,int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        it->second = i;
        i++;
    }
    for (int i = 0; i < N; i++)
        cout << m[arr[i]] << ' ';
    return (0);
}