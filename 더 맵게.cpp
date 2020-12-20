//
// Created by 0864h on 2020-12-20.
//
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    for(int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    int sv = 0;
    int count = 0;
    while(pq.top() < K)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        count++;
        sv = first + second * 2;
        pq.push(sv);
        if(pq.size() == 1 && pq.top() < K)
            return answer;
    }
    answer = count;
    return answer;
}
