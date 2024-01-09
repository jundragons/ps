#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int graph[101][101][101];
int visited[101][101][101];

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

queue<pair<int, pair<int, int>>> toma;

void bfs() {
	while (toma.size()) {
		auto temp = toma.front();
		toma.pop();
		for (int i = 0; i < 6; i++) {
			int nx = temp.second.first + dx[i];
			int ny = temp.second.second + dy[i];
			int nz = temp.first + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (visited[nz][nx][ny] >= 0) continue;
			visited[nz][nx][ny] = visited[temp.first][temp.second.first][temp.second.second] + 1;
			toma.push({ nz,{nx,ny} });
		}
	}
}

int main() {

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[k][i][j];
				if(graph[k][i][j]==1)
					toma.push({ k,{i,j} });
				if (graph[k][i][j] == 0)
					visited[k][i][j] = -1;
			}
		}
	}
	bfs();
	int ans = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[k][i][j] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(visited[k][i][j], ans);
			}
		}
	}
	cout << ans;
}