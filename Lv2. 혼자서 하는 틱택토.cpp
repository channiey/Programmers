//https://school.programmers.co.kr/learn/courses/30/lessons/160585

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
        
    bool isWin = false;
    char winner = '.';
    for(int i = 0; i < 3; i++)
    {
        if('.' != board[i][0] && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
        {
            if(isWin)
            {
                if(winner != board[i][0])
                    return 0;
            }
            
            isWin = true;
            winner = board[i][0];
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        if('.' != board[0][i] && board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
        {
            if(isWin)
            {
                if(winner != board[0][i])
                    return 0;
            }
            
            isWin = true;
            winner = board[0][i];
        }
    }
    
    if('.' != board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        if(isWin)
        {
            if(winner != board[0][0])
                return 0;
        }

        isWin = true;
        winner = board[0][0];
    }
   
    if('.' != board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0])  
    {
        if(isWin)
        {
            if(winner != board[0][2])
                return 0;
        }

        isWin = true;
        winner = board[0][2];
    }
  
    
    int numPost = 0, numPre = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if('O' == board[i][j])
                numPre++;
            else if('X' == board[i][j]) 
                numPost++;
        }
    }
    
    
    if(numPre < numPost || numPre > numPost + 1)
        return 0;
    
    if(isWin)
    {
        if('O' == winner && numPre != numPost + 1)
            return 0;
        else if('X' == winner && numPre != numPost)
            return 0;
    }
    
    return 1; 
}
