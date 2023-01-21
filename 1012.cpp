#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y;
int board[51][51];
int visited[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= 50 || ny >= 50) continue;
			if (visited[nx][ny] || board[nx][ny] == 0) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	int n_test;
	cin >> n_test;
	while (n_test--) {
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));

		cin >> m >> n >> k;
		
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[y][x] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] && visited[i][j] == 0) {
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}