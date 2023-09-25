#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(a) (a).begin(),(a).end()
const int INF = 0x3f3f3f3f;

const int maxn = 12;
bool visited[maxn][maxn];
pair<int,int> limites[maxn];
int rows, maxcolumn;
int rc, cl;
int finalcount;

pair<int,int> moves[] = {
	{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
	{1,-2}, {1,2}, {2, -1}, {2, 1}
};

bool onboard(int nx, int ny){
	if(nx < 0 || nx >= rows){
		return false;
	} else {
		if(ny < limites[nx].first || ny >= limites[nx].second) return false;
		return true;
	}
	return true;
}

void backtracking(int i, int j, int wasvisited){
	finalcount = max(finalcount, wasvisited);
	for(int idx = 0; idx < 8; idx++){
		int nx = i + moves[idx].first, ny = j + moves[idx].second;
		if(!visited[nx][ny] && onboard(nx,ny)){
			visited[nx][ny] = true;
			backtracking(nx, ny, wasvisited+1);
			visited[nx][ny] = false;
		}
	}
}

int main(){
    int cases = 0;

	while(cin >> rows && rows){
		finalcount = 0;
		int cells = 0;
		memset(visited, false, sizeof visited);

		for(int i=0 ; i < rows; i++){
			cin >> rc >> cl;
			cells += cl;
			limites[i].first = rc;
			limites[i].second = rc + cl;
		}
		
		visited[0][0] = true;
		backtracking(0, 0, 1);

		string sqrs = (cells-finalcount == 1 ? "square" : "squares");

		cout << "Case " << ++cases << ", " << cells - finalcount << " " << sqrs << " can not be reached." << endl;
	}
	return 0;
}