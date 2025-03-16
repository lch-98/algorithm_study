#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt = 0;
vector<int> maze;
vector<int> right_digonal;
vector<int> left_digonal;
void dfs(int row)
{
    if(row == N)
    {
        cnt++;
        return;
    }
    
    for (int col=0; col<N; col++)
    {
        if (maze[col]==1) continue;
        if (right_digonal[row+col]==1) continue;
        if (left_digonal[row-col+N-1]==1) continue;
        
        maze[col] = 1;
        right_digonal[row+col] = 1;
        left_digonal[row-col+N-1] = 1;
        
        dfs(row+1);
        
        maze[col] = 0;
        right_digonal[row+col] = 0;
        left_digonal[row-col+N-1] = 0;
    }      
}    

int main()
{
    cin >> N;
    maze = vector<int> (N,0);
    left_digonal = vector<int> (N*2,0);
    right_digonal = vector<int> (N*2,0);
    
    dfs(0);
    cout << cnt;
}