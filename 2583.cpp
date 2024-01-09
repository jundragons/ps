#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int graph[110][110];
int visited[110][110];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int a, int b) {
	int ret = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || graph[nx][ny]) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
			ret++;
		}
	}
	return ret;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				graph[j][i] = 1;
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0 && visited[i][j] == 0) {
				v.push_back(bfs(i, j));
			}
		}
	}
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (int num : v) {
		cout << num << ' ';
	}
}