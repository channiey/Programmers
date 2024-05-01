// https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std; 

int solution(int x, int y, int n) {

    if (x == y)
        return 0;

    int answer = 0;

    queue<pair<int, int>> q; // value, level
    set<int> visited;

    visited.insert(x);
    q.push({ x, 0 });

    while (q.size())
    {
        const auto& data{ q.front() };
        q.pop();

        if (data.first == y)
        {
            answer = data.second;
            break;
        }
        else if (data.first < y)
        {
            int newX{ data.first * 2 };
            if (visited.insert(newX).second)
                q.push({ newX, data.second + 1 });

            newX = data.first * 3;
            if (visited.insert(newX).second)
                q.push({ newX, data.second + 1 });

            newX = data.first + n;
            if (visited.insert(newX).second)
                q.push({ newX, data.second + 1 });
        }
    }

    if (0 == answer)
        return -1;

    return answer;
}
