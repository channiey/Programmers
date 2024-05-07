// https://school.programmers.co.kr/learn/courses/30/lessons/147354

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {

    int answer = 0;
    col -= 1;

    sort(data.begin(), data.end(), [col](const auto& v1, const auto& v2) {
        return (v1[col] == v2[col]) ? v1.front() > v2.front() : v1[col] < v2[col];
        });

    for (int i = row_begin; i <= row_end; i++)
    {
        int sum = 0;

        for (const int j : data[i - 1])
            sum += j % i;

        answer ^= sum;
    }

    return answer;
}
