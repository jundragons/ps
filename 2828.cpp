#include <bits/stdc++.h>
using namespace std;

int n, len, j, loc;
int arr[15];
int ans = 0;

int main() {
	cin >> n >> len >> j;
	int startP = 1;
	int endP = len;
	for (int i = 0; i < j; i++) {
		cin >> loc;
		if (loc > endP) {
			int dis = loc - endP;
			startP += dis;
			endP += dis;
			ans += dis;
		}
		else if (loc < startP) {
			int dis = startP - loc;
			startP -= dis;
			endP -= dis;
			ans += dis;
		}
	}
	cout << ans;

}