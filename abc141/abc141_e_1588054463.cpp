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

int bpm(int x, unsigned int y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (unsigned int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}

typedef unsigned int ull;
const ull B1 = 100000007;
const ull B2 = 1000000007;
bool contain(string &a, string &b) {
  int al = a.length(), bl = b.length();
  if (al > bl) return false;
  ull t1 = 1, t2 = 1;
  for (int i = 0; i < al; i++) t1 *= B1;
  for (int i = 0; i < al; i++) t2 *= B2;
  ull ah1 = 0, bh1 = 0, ah2 = 0, bh2 = 0;
  for (int i = 0; i < al; i++) ah1 = ah1 * B1 + a[i];
  for (int i = 0; i < al; i++) ah2 = ah2 * B2 + a[i];
  for (int i = 0; i < al; i++) bh1 = bh1 * B1 + b[i];
  for (int i = 0; i < al; i++) bh2 = bh2 * B2 + b[i];
  for (int i = 0; i + al <= bl; i++) {
    if (ah1 == bh1 and ah2 == bh2) return true;
    if (i + al < bl) bh1 = bh1 * B1 + b[i + al] - b[i] * t1;
    if (i + al < bl) bh2 = bh2 * B2 + b[i + al] - b[i] * t2;
  }
  return false;
}

signed main() {
  int N;
  string S;
  cin >> N >> S;
  int ans  = 0;
  string L = "", R;
  rep(i, N - 1) {
    R = "";
    L += S[i];
    rep(j, N - (i + 1)) {
      R += S[(i + 1) + j];
      if (contain(R, L)) ans = max(ans, (int)R.size());
    }
  }
  cout << ans << endl;
}