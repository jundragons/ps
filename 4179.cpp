#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int n, m;
char graph[MAX][MAX];
int fireSpread[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int, int>> jihun;
queue<pair<int, int>> fQ;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string str;


int bfs() {
	while (jihun.size()) {
		auto temp = jihun.front();
		jihun.pop();
		int moveCnt = visited[temp.first][temp.second];
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				return moveCnt+ 1;
			}
			if (graph[nx][ny] == '#') continue;
			if (visited[nx][ny]!=-1) continue;
			if (fireSpread[nx][ny]!=-1 &&fireSpread[nx][ny] <= moveCnt + 1) continue;
			visited[nx][ny] = moveCnt + 1;
			jihun.push({ nx,ny });
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(fireSpread, -1, sizeof(fireSpread));
	memset(visited, -1, sizeof(visited));
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			graph[i][j] = str[j];
			if (graph[i][j] =='J') {
				jihun.push({ i,j });
				visited[i][j] = 0;
			}
			else if (graph[i][j] == 'F') {
				fQ.push({ i,j });
				fireSpread[i][j] = 0;
			}
		}
	}
	while (fQ.size()) {
		auto temp = fQ.front();
		fQ.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] == '#') continue;
			if (fireSpread[nx][ny] != -1) continue;
			fireSpread[nx][ny] = fireSpread[temp.first][temp.second] +1;
			fQ.push({ nx,ny });
		}
	}
	
	int ans = bfs();

	if (ans == -1) {
		cout << "IMPOSSIBLE";
	}
	else cout << ans;
	
}