#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    for (int col = sqrt(area); col >= 3; col--)
    {
        if (area % col == 0)
        {
            int row = area / col;
            if ((row-2) * (col-2) == yellow)
            {
                answer.push_back(row);
                answer.push_back(col);
                break;
            }   
        }
    }
    return answer;
}