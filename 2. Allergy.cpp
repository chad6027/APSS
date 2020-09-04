//어디가 틀린거지?

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;
int ans, n , m, cnt = 0;
bool a[50][50];
bool isEaten[50];
vector<int> menu;
vector<pair<string,int>> v[26];
bool canEverybodyEat() {
	bool can = true;
	memset(isEaten, 0, sizeof(isEaten));
	for (int i = 0; i < menu.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (a[menu[i]][j]) {
				isEaten[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!isEaten[i]) {
			can = false;
			break;
		}
	}
	return can;
}
int DFS(int food) {
	if (food == m) {
		if (canEverybodyEat()) {
			return menu.size();
		}
		return 987654321;
	}

	int ret = DFS(food + 1);
	menu.push_back(food);
	ret = min(ret, DFS(food + 1));
	menu.pop_back();
	return ret;
}



int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(false);
	int T, tmp, index;
	string s;
	cin >> T;

	while(T--) {
		for (int i = 0; i < 26; i++)
			v[i].clear();
		menu.clear();
		memset(a, 0, sizeof(a));

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			v[s[0] - 'a'].push_back({ s, i });
		}

		for (int i = 0; i < m; i++) {
			cin >> tmp;
			for (int j = 0; j < tmp; j++) {
				cin >> s;
				for (int k = 0; k < v[s[0] - 'a'].size(); k++) {
					if (v[s[0] - 'a'][k].first == s) {
						index = v[s[0] - 'a'][k].second;
						break;
					}
				}
				a[i][index] = true;
			}
		}

		ans = DFS(0);
		printf("%d\n", ans);
	}

	return 0;
}