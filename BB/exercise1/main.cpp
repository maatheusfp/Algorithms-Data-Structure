#include <iostream>
#include <vector>

using namespace std;

int n, m, cap;
vector<string> g;
vector<vector<vector<int>>> v;
int move_x[] = {0, 0, 1, -1};
int move_y[] = {1, -1, 0, 0};

void dfs(int x, int y, int j) {
    if (j > 10) {
        return;
    }
    if (v[x][y][j] == 1) {
        return;
    }
    v[x][y][j] = 1;

    for (int i = 0; i < 4; i++) {
        int temp_x = x + move_x[i];
        int temp_y = y + move_y[i];
        int temp_j = j;
        if (g[temp_x][temp_y] == '#') {
            continue;
        }
        if (g[temp_x][temp_y] == 's') {
            temp_j++;
        }
        dfs(temp_x, temp_y, temp_j);
    }
}

int main() {
    cin >> n >> m >> cap;
    g.push_back(string(m + 2, '#'));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        g.push_back('#' + row + '#');
    }
    g.push_back(string(m + 2, '#'));

    v = vector<vector<vector<int>>>(n + 2, vector<vector<int>>(m + 2, vector<int>(11, 0))); // Corrigido o tamanho do vetor

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'x') {
                dfs(i, j, 0);
                break;
            }
        }
    }

    string ans = "IMPOSSIBLE";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '@') {
                for (int count = 0; count <= cap / 2; count++) {
                    if (v[i][j][count] == 1) {
                        ans = "SUCCESS";
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}