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

class CTrainTicket {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    string S;
    cin >> S;
    int A = S[0] - '0', B = S[1] - '0', C = S[2] - '0', D = S[3] - '0';
    string ans;
    if (A + B + C + D == 7) {
      ans = "A+B+C+D=7";
    } else if (A - B + C + D == 7) {
      ans = "A-B+C+D=7";
    } else if (A - B - C + D == 7) {
      ans = "A-B-C+D=7";
    } else if (A - B - C - D == 7) {
      ans = "A-B-C-D=7";
    } else if (A - B + C - D == 7) {
      ans = "A-B+C-D=7";
    } else if (A + B - C + D == 7) {
      ans = "A+B-C+D=7";
    } else if (A + B - C - D == 7) {
      ans = "A+B-C-D=7";
    } else {
      ans = "A+B+C-D=7";
    }
    rep(i, ans.size()) {
      if (ans[i] == 'A') ans[i] = '0' + A;
      if (ans[i] == 'B') ans[i] = '0' + B;
      if (ans[i] == 'C') ans[i] = '0' + C;
      if (ans[i] == 'D') ans[i] = '0' + D;
    }
    cout << ans << endl;
  }
};
