//my solution to this problem: https://algotester.com/en/ArchiveProblem/DisplayWithEditor/20031
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define ll unsigned long long
ll n, m, s, f, v1, v2, ans;
ll vis[1'000'010];
vector<ll> g[1'000'010];
deque <pair<ll, ll>> deq;
const ll mod = 1'000'000'007;

void bfs() {
	while (deq.size() > 0) {
		ll v = deq.back().first;
		ll dis = deq.back().second;
		deq.pop_back();

		if (vis[v] > dis) {
			vis[v] = dis;
			for (auto to : g[v]) {
				if (vis[to] > vis[v] + 1) deq.push_front({ to, vis[v] + 1 });
			}
		}
	}
}

void ways(ll v) {
	ll cou = 0;

	for (auto to : g[v]) {

		if (vis[to] + 1 == vis[v]) {
			cou++;
			ways(to);
		}

	}

	if (cou > 1) {
		ans = (ans + (cou - 1) % mod) % mod;
	}
}

int main() {
	cin >> n >> m;
	cin >> s >> f;
	for (ll i = 1; i <= m; i++) {
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	fill_n(vis, n + 10, 1'000'000'010);
	deq.push_front({ s, 0 });

	bfs();
	ans = 1;
	ways(f);

	if (vis[f] != 1'000'000'010)
		cout << ans << "\n";
	else
		cout << 0 << "\n";
}
