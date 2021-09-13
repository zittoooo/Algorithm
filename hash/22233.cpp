#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> keywords;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    string word;

    cin >> N >> M;
    for (int i = 0; i < N ; i++)
    {
        cin >> word;
        keywords.insert({word, 1});
    }
    
    for (int i = 0; i < M; i++)
    {
        cin >> word;
        string tmp;
        int k = 0;
        while (1)
        {
            if (word[k] == ',' || word[k] == '\0')
            {
                if (keywords.find(tmp) != keywords.end())
                    keywords.erase(tmp);
                tmp.clear();
                if (word[k] == '\0')
                    break;
            }
            else
                tmp += word[k];
            
            if (keywords.size() == 0)
                break ;
            k++;
        }
        cout << keywords.size() << '\n';
    }
    return 0;
}