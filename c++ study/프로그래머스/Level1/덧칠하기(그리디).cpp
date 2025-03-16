#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int i = 0;
    int size = section.size();
    
    while(i < size)
    {
        int start_pos = section[i];
        answer++;
        
        // 롤러가 덮을 수 있는 최대 범위를 계산
        int end = start_pos + m - 1;
        
        // 현재 롤러가 덮을 수 있는 범위 내에 있는 모든 섹션을 건너뜀
        while (i < size && section[i] <= end)
        {
            i++;
        }
    }
    
    return answer;
}
