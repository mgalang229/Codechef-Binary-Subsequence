#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		// count the total number of ones and zeroes in the string
		int total_zeroes = 0;
		int total_ones = 0;
		for (int i = 0; i < n; i++) {
			total_zeroes += (s[i] == '0');
			total_ones += (s[i] == '1');
		}
		// there will be three (3) cases:
		// case 1 - remove all the zeroes (i.e, 111111...)
		// case 2 - remove all the ones (i.e., 00000...)
		// case 3 - first half must be all 0s and second half must be all 1s (i.e., 0000...111...)
		// for the third case, we should identify the turning point (from 0 to 1) and count the
		// 1s before this particular 0 and add the remaining zeroes after it since the second half
		// should be all 1s (i.e., 000...'0'1111..., turning point is in single quotation marks)
		int ans = min(total_zeroes, total_ones);
		int current_zeroes = 0;
		int current_ones = 0;
		for (int i = 0; i < n; i++) {
			current_zeroes += (s[i] == '0');
			current_ones += (s[i] == '1');
			ans = min(ans, current_ones + (total_zeroes - current_zeroes));
		}
		cout << ans << '\n';
	}
	return 0;
}
