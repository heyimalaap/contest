// https://codeforces.com/contest/1384/problem/C

#include <bits/stdc++.h>

#define PI  3.141592
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		string A, B;
		cin >> A >> B;

		ll count = 0;
		bool can = true;

		for (ll i = 0; i < n; i++)
			if (A[i] > B[i]) can = false;	

		if (can) {
			for (char c = 'a'; c <= 't'; c++) {
				char min_c = 't';
				vector<ll> flip;
				for (ll i = 0; i < n; i++) {
					if (B[i] != A[i] && A[i] == c) {
						flip.push_back(i);
						if (B[i] < min_c) min_c = B[i];
					}
				}

				if (flip.size() != 0) {
					count++;
					for (ll i : flip) {
						A[i] = min_c;
					}
				}
			}
			cout << count << endl;
		} else {
			cout << "-1" << endl;
		}
	}

    return 0;
}

