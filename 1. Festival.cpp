// 1. Festival
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n[1001];

int main() {
	int C, N, L;
	double ans, tmp;
	queue<int> que;

	cin >> C;
	while(C--) {
		ans = 987654321, tmp = 0;
		cin >> N >> L;
		n[0] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> n[i];
			n[i] += n[i - 1];
		}
		for (int i = L; i <= N; i++) {
			for (int j = 1; j <= i - L + 1; j++) {
				tmp = (double) (n[i] - n[j - 1]) / (double) (i - j + 1);
				ans = min(ans, tmp);
			}
		}
		printf("%0.10f\n", ans);

	}

	return 0;
}