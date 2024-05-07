// https://school.programmers.co.kr/learn/courses/30/lessons/142085

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {    
   
    int sum {};
    priority_queue<int, vector<int>, greater<>> pq; // 최소힙
    
    for(int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);
        
        if(pq.size() > k) // 힙의 사이즈를 무적권의 개수만큼 유지
        {
            sum += pq.top(); // 최솟값 누적
            pq.pop();
        }
        
        if(sum > n) // 다음 라운드 진행 불가 (n은 고정)
            return i;
    }
    return enemy.size(); // 모든 라운드 통과
}
