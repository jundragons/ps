#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[101][101];
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			graph[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, int >> q;
	q.push({0,0});
	visited[0][0] = 1;
	while (q.size()) {
		auto temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || graph[nx][ny] == 0) continue;
			visited[nx][ny] = visited[temp.first][temp.second] + 1;
			q.push({ nx,ny });
		}

	}
	cout << visited[n-1][m-1];
}	