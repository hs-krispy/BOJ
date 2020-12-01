//
// Created by 0864h on 2020-12-02.
//
#include <string>
#include <vector>
#include <climits>
using namespace std;
bool check[50];
int Min = INT_MAX;
void transform(string begin, string target, vector<string> words, int ans)
{
    if(begin == target)
    {
        if(Min > ans)
            Min = ans;
        return;
    }
    for(int i = 0; i < words.size(); i++)
    {
        int count = 0;
        if(!check[i])
        {
            for(int j = 0; j < words[i].length(); j++)
            {
                if(begin[j] == words[i][j])
                    count++;
            }
            if(count == words[i].length() - 1)
            {
                check[i] = true;
                transform(words[i], target, words, ans + 1);
                check[i] = false;
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    bool exist = false;
    for(int i = 0; i < words.size(); i++)
    {
        if(target == words[i])
        {
            exist = true;
            break;
        }
    }
    if(exist)
        transform(begin, target, words, 0);
    else Min = 0;
    return Min;
}
