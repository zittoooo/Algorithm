#include <string>
#include <vector>

using namespace std;
void func(int cur, int target, int res, int *answer, vector<int> &numbers)
{
    if (cur == numbers.size())
    {
        if (res == target)
            ++(*answer);
        return ;
    }
    
    func(cur + 1, target, res + numbers[cur], answer, numbers);
    func(cur + 1, target, res - numbers[cur], answer, numbers);
}

int solution(vector<int> numbers, int target) {  
    int answer = 0;
    func(0, target, 0, &answer ,numbers);
    
    return answer;
}
