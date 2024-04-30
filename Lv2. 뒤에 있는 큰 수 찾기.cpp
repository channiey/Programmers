// https://school.programmers.co.kr/learn/courses/30/lessons/154539

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> stk;
    
    for(int i = numbers.size() - 1; 0 <= i; i--)
    {
        while(stk.size())
        {
            if(stk.top() > numbers[i])
            {
                answer[i] = stk.top(); 
                break;
            }
            stk.pop(); 
        }
        stk.push(numbers[i]);
    }
    return answer;
}
