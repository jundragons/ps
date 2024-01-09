#include <bits/stdc++.h>
using namespace std;

//RGB
//적록 (RG) ,(B)
int n;
char graph[101][101];
int visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int a, int b) {
	queue<pair<int, int >> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front();
		q.pop();
		char cur = graph[temp.first][temp.second];
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= 100 || ny>100) continue;
			if (visited[nx][ny]) continue;
			if (graph[nx][ny] != cur) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			graph[i][j] = str[j];
		}
	}

	int p1 = 0;
	int p2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
				p1++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 'G')
				graph[i][j] = 'R';
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
				p2++;
			}
		}
	}

	cout << p1 << ' ' << p2;
}