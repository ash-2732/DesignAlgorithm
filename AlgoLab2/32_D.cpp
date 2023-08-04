#include <iostream>
#include <vector>

using namespace std;

void DFS(int i, int j, int N, int M, vector<vector<char>>& grid, vector<vector<bool>>& visit) {
    if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] == '#' || visit[i][j])
        return;

    visit[i][j] = true;
    DFS(i - 1, j, N, M, grid, visit); 
    DFS(i + 1, j, N, M, grid, visit); 
    DFS(i, j - 1, N, M, grid, visit); 
    DFS(i, j + 1, N, M, grid, visit); 
}

int countConnectedAreas(int N, int M, vector<vector<char>>& grid) {
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    int count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '.' && !visit[i][j]) {
                DFS(i, j, N, M, grid, visit);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
    int connectedAreas = countConnectedAreas(N, M, grid);
    cout << connectedAreas << endl;

    return 0;
}