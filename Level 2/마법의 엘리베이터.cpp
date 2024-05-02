// https://school.programmers.co.kr/learn/courses/30/lessons/148653

#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while(0 < storey)
    {
        const int remainder{ storey % 10 };
        
        if(remainder < 5)
        {
            storey -= remainder;
            answer += remainder;
        }
        else if (5 < remainder)
        {
            storey += 10 - remainder;
            answer += 10 - remainder;
        }   
        else if (5 == remainder)
        {
            const int nextRemainder {storey / 10 % 10};
            
            if(nextRemainder < 5)
                storey -= remainder;
            else
                storey += remainder;
            
            answer += remainder;
        }
       
        storey /= 10;
    }
    
    return answer;
}
