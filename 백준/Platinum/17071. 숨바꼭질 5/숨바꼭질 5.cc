#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, K, ans;
int visit[2][500001]; // 홀수 시간 대에 방문했다면 [0], 짝수 시간 대에 방문했다면 [1]에 시간 기록

int bfs() {
	queue<tuple<int, int, int>> q; // pair<수빈, 동생, 시간>
	q.push({N, K, 1});

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int subin, sister, time;
		tie(subin, sister, time) = cur;
		int sisterNext = sister;

		// 찾았으면 종료
		if (subin == sister) {
			return time - 1;
		}
		// 수빈이 왔던 곳이고 기다릴 수 있는(+1, -1로) 자리면
		int ans = 1e9;
		bool flag = false;
		// visit <= time : 방문했던 시점이 과거여야 함
		if (visit[0][sister] > 0 && visit[0][sister] <= time && time % 2 == 0) { // 짝수
			ans = time - 1;
			flag = true;
		}
		if (visit[1][sister] > 0 && visit[1][sister] <= time && time % 2 == 1) { // 홀수
			ans = min(ans, time - 1);
			flag = true;
		}
		// 현재 시간 반환하고 종료
		if (flag)
			return ans;

		// time 1000이 넘으면 1부터 시작해도 50만을 넘김
		if (time > 1000 || sisterNext > 500000)
			continue;

		// 홀수, 짝수 시간 나누어 BFS
		sisterNext += time;
		int nextTime = time + 1;
		if (subin - 1 > 0) {
			if (!visit[0][subin - 1] && nextTime % 2 == 0) {
				visit[0][subin - 1] = nextTime;
				q.push({ subin - 1, sisterNext, nextTime });
			}
			else if (!visit[1][subin - 1] && nextTime % 2 == 1) {
				visit[1][subin - 1] = nextTime;
				q.push({ subin - 1, sisterNext, nextTime });
			}
		}
		if (subin + 1 < 500001) {
			if (!visit[0][subin + 1] && nextTime % 2 == 0) {
				visit[0][subin + 1] = nextTime;
				q.push({ subin + 1, sisterNext, nextTime });
			}
			else if (!visit[1][subin + 1] && nextTime % 2 == 1) {
				visit[1][subin + 1] = nextTime;
				q.push({ subin + 1, sisterNext, nextTime });
			}
		}
		if (subin * 2 < 500001) {
			if (!visit[0][subin * 2] && nextTime % 2 == 0) {
				visit[0][subin * 2] = nextTime;
				q.push({ subin * 2, sisterNext, nextTime });
			}
			else if (!visit[1][subin * 2] && nextTime % 2 == 1) {
				visit[1][subin * 2] = nextTime;
				q.push({ subin * 2, sisterNext, nextTime });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	cout << bfs();
	return 0;
}