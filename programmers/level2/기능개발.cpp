#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
stack<int> s;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    for (int i = progresses.size() - 1; i >= 0 ; i--)
    {
        int out = ceil((double)(100 - progresses[i]) / speeds[i]);
        s.push(out);
    }
    while (!s.empty())
    {
        int cnt = 0;
        int cur = s.top(); s.pop();
        cnt++;
        while (!s.empty() && s.top() <= cur)
        {
            cnt++;
            s.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}