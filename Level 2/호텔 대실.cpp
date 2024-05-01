// https://school.programmers.co.kr/learn/courses/30/lessons/155651

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int ConvertStringToInt(const string& time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    sort(book_time.begin(), book_time.end());
    
    for(const auto& time : book_time)
    {
        const int startTime{ConvertStringToInt(time[0])};
        const int endTime{ConvertStringToInt(time[1]) + 10};
        
        while(pq.size() && pq.top() <= startTime)
            pq.pop();
        
        pq.push(endTime);
        
        answer = max(answer, (int)pq.size());
    }
    
    return answer;
}
