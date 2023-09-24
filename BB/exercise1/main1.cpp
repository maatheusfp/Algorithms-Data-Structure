#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int rows, cols, capacity;
vector<string> grid;
vector<vector<vector<int>>> visited;
int move_x[] = {0, 0, 1, -1};
int move_y[] = {1, -1, 0, 0};

void dfs(int x, int y, int steps) {
    if (steps > 10) {
        return;
    }
    if (visited[x][y][steps] == 1) {
        return;
    }
    visited[x][y][steps] = 1;

    for (int i = 0; i < 4; i++) {
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];
        int next_steps = steps;
        if (grid[next_x][next_y] == '#') {
            continue;
        }
        if (grid[next_x][next_y] == 's') {
            next_steps++;
        }
        dfs(next_x, next_y, next_steps);
    }
}

int main() {
    cin >> rows >> cols >> capacity;
    grid.push_back(string(cols + 2, '#'));
    for (int i = 0; i < rows; i++) {
        string row;
        cin >> row;
        grid.push_back('#' + row + '#');
    }
    grid.push_back(string(cols + 2, '#'));

    visited = vector<vector<vector<int>>>(rows + 2, vector<vector<int>>(cols + 2, vector<int>(11, 0)));

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (grid[i][j] == 'x') {
                dfs(i, j, 0);
                break;
            }
        }
    }

    string result = "IMPOSSIBLE";
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (grid[i][j] == '@') {
                for (int count = 0; count <= capacity / 2; count++) {
                    if (visited[i][j][count] == 1) {
                        result = "SUCCESS";
                        break;
                    }
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}