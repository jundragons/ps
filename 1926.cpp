#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[510][510];
int visited[510][510];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;

int bfs(int a, int b) {
	int size = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;

	while (q.size()) {
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (visited[nx][ny]||graph[nx][ny]==0) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
			size++;
		}
	}
	return size;
}

int main() {
	int picNum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] && !visited[i][j]) {
				int len = bfs(i, j);
				ans = max(len, ans);
				picNum++;
			}
		}
	}
	cout << picNum << '\n';
	cout << ans;

}