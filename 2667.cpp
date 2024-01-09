#include <bits/stdc++.h>
using namespace std;

int n;
int graph[26][26];
int visited[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	int ret = 1;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] || graph[nx][ny] == 0) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
			ret++;
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			graph[i][j] = str[j] - '0';
		}
	}
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] && visited[i][j] == 0) {
				v.push_back(bfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int num : v) {
		cout << num << '\n';
	}
}