// https://school.programmers.co.kr/learn/courses/30/lessons/152996

#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<long long> cnt(1001, 0);
    for(const int& weight : weights)
        cnt[weight]++;
    
    for(const int& weight : weights)
    {
        // 2 : 3
        if(0 == weight % 2)
        {
            const long long base = weight / 2 * 3;
            if(base <= 1000)
                answer += cnt[base];
        }
        
        // 3 : 3
        if(0 == weight % 3)
        {
            const long long base = weight / 3 * 4;
            if(base <= 1000)
                answer += cnt[base];
        }
        
        // 1 : 2 (2 : 4)
        const long long base = weight * 2;
            if(base <= 1000)
                answer += cnt[base];
    }
    
    // 몸무게가 같은 경우
    for(int i = 100; i <= 1000; i++)
    {
        if (2 <= cnt[i])
            answer += (long long)(cnt[i] * (cnt[i]-1)) / 2;
            // n개 중에 2개 뽑는 경우의 수 : n(n-1) / 2
    }
    
    return answer;
}
