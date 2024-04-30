// https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using COORD = pair<int, int>;

bool visited[100][100]{};
const int dRow[4]{-1, 0, 1, 0}; 
const int dCol[4]{0, 1, 0, -1};

const int BFS(const vector<string>& maps, const int& row, const int& col, 
              const int& maxRow, const int& maxCol) {
    queue<COORD> coords;
    int days{maps[row][col] - '0'};
    
    visited[row][col] = true;
    coords.push({row, col});

    while(coords.size())
    {
        const COORD curCoord{coords.front()};
        coords.pop();
        
        for(int i = 0; i < 4; i++)
        {
            const int newRow {curCoord.first + dRow[i]};
            const int newCol {curCoord.second + dCol[i]};
            
            if(0 > newRow || maxRow <= newRow || 0 > newCol || maxCol <= newCol)
                continue;
            
            if(visited[newRow][newCol] || !isdigit(maps[newRow][newCol]))
                continue;
            
            days += maps[newRow][newCol] - '0';
            visited[newRow][newCol] = true;
            coords.push({newRow, newCol});
        }
    }
    
    return days;
}

vector<int> solution(vector<string> maps) {    

    vector<int> answer;
    const int maxRow{(int)maps.size()};
    const int maxCol{(int)maps.front().size()};
    
    for(int row = 0; row < maxRow; row++)
    {
        for (int col = 0; col < maxCol; col++)
        {
            if(!visited[row][col] && isdigit(maps[row][col]))
                answer.push_back(BFS(maps, row, col, maxRow, maxCol));
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer; 
}
