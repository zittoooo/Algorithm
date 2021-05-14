#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, tmp,arr[1005], mx;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    vector<int> cmb;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int k = 3;
    for(int i = 0 ; i< k ; i++)
        cmb.push_back(1);
    for(int i = 0 ; i < v.size()-k; i++)
        cmb.push_back(0);
    sort(cmb.begin(), cmb.end());
    do {
        tmp = 0;
        for (int i = 0; i < cmb.size(); i++)
        {
            if (cmb[i] == 1)
                tmp += v[i];
        }
        if (tmp <= M)
            mx = max(tmp, mx);
    } while(next_permutation(cmb.begin(), cmb.end()));
    cout << mx;
}
