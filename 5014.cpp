#include <bits/stdc++.h>
using namespace std;

int total, to, here, up, down;
int arr[1000001];

int main() {
	cin >> total >> here >> to >> up >> down;
	memset(arr, -1, sizeof(arr));
	arr[here] = 0;
	queue<int> q;
	q.push(here);
	while (q.size()) {
		auto temp = q.front(); q.pop();
		if (temp == to) break;
		int nx = temp + up;
		if (nx <= total && arr[nx] == -1) {
			arr[nx] = arr[temp] + 1;
			q.push({ nx });
		}
		nx = temp - down;
		if (nx >= 1 && arr[nx] == -1) {
			arr[nx] = arr[temp] + 1;
			q.push({ nx });
		}
	}
	if (arr[to] == -1) {
		cout << "use the stairs";
	}
	else cout << arr[to];
}