#include <bits/stdc++.h>
using namespace std;

int n_test;
int visited[301][301];
int n,fromX, fromY, toX, toY;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 0;
	while (q.size()) {
		auto temp = q.front(); q.pop();
		if (temp.first == toX && temp.second == toY)
			return;
		for (int i = 0; i < 8; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] != -1) continue;
			visited[nx][ny] = visited[temp.first][temp.second] + 1;
			q.push({ nx,ny });
		}

	}
}
int main() {
	cin >> n_test;
	while (n_test--) {
		cin >> n;
		cin >> fromX >> fromY >> toX >> toY;
		memset(visited, -1, sizeof(visited));
		bfs(fromX, fromY);
		cout << visited[toX][toY] << '\n';
	}
}