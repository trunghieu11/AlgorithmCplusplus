using namespace std;
#include <bits/stdc++.h>
#include "../library/ArraysUtils.hpp"

class TaskB {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int from = (1 << n);
		int to = (1 << (n + 1));
		int A[to];
		for (int i = 2; i < to; i++) {
			in >> A[i];
		}

		int maxVal = 0;
		int sum[to];
		memset(sum, 0, sizeof(sum));
		for (int i = from; i < to; i++) {
			int cur = i;

			while (cur > 1) {
				sum[i] += A[cur];
				cur /= 2;
			}

			maxVal = max(sum[i], maxVal);
		}

		int need[to];
		memset(need, 0, sizeof(need));
		for (int i = from; i < to; i++) {
			need[i] = maxVal - sum[i];
		}

		for (int i = to - 1; i > 1; i -= 2) {
			int same = min(need[i], need[i - 1]);
			need[i / 2] += same;
			need[i] -= same;
			need[i - 1] -= same;
		}

		out << ArraysUtils::sumArray(need, to);
	}
};
