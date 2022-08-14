#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}
int bpm(int x, int y) {
  if (x == 0)
    return 0;
  else if (y == 0) {
    return 1;
  }
  int ans = 1;
  x %= MOD;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = x * x;
    x %= MOD;
  }
  return ans;
}

class DDiceInLine {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N, K;
    cin >> N >> K;
    vector<double> cum_sum(N + 1, 0);
    rep(i, N) {
      double temp;
      cin >> temp;
      cum_sum[i + 1] = (temp + 1) / 2;
      cum_sum[i + 1] += cum_sum[i];
    }
    double sum = 0;
    rep(i, N - K + 1) {
      sum = max(sum, cum_sum[i + K] - cum_sum[i]);
    }
    cout << fixed << sum << setprecision(15) << endl;
  }
};
