#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int visited[101][101];
int n, height;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int a, int b, int cur) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] || arr[nx][ny] <= cur) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			height = max(height, arr[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= height; i++) {
		memset(visited, 0, sizeof(visited));
		int ret = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (visited[a][b] == 0 && arr[a][b] > i) {
					bfs(a, b, i);
					ret++;
				}
			}
		}
		ans = max(ans, ret);
	}
	cout << ans;
}