#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100010];
int dx[2] = { 1,-1 };

int main() {
	cin >> n >> k;
	memset(arr, -1, sizeof(arr));
	queue<int> q;
	q.push(n);
	arr[n] = 0;
	while (q.size()) {
		auto temp = q.front();
		q.pop();
		if (temp == k) break;
		for (int nx : {temp - 1, temp + 1, temp * 2}) {
			if (nx < 0 || nx>100000) continue;
			if (arr[nx] != -1) continue;
			arr[nx] = arr[temp] + 1;
			q.push(nx);
		}
	}
	cout << arr[k];
}