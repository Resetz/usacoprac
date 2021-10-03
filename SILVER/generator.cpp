#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::mt19937 rng(1377);
	const int INF = 1e9;
	const int n = 1e5;
	std::cout << n << ' ' << n << '\n';
	std::set<std::pair<int, int>> st;
	for(int i = 0; i < n; i++) {
		int u, v;
		do {
			u = rng() % n + 1;
			v = rng() % n + 1;
		} while(u == v || st.count({u, v}) + st.count({v, u}));
		std::cout << u << " " << v << " " << INF << '\n';
		st.insert({u, v});
	}
	std::cout << n << '\n';
	for(int i = 0; i < n; i++) {
		int u, v;
		do {
			u = rng() % n + 1;
			v = rng() % n + 1;
		} while(u == v || st.count({u, v}) + st.count({v, u}));
		std::cout << "1 " << u << " " << v << " " << INF / 2 - i << '\n';
		st.insert({u, v});
	}
}