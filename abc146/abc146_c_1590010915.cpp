/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl                endl

using namespace std;
const int MOD   = (int)(1e9 + 7);
const int INF   = (int)(1e13 + 7);
const double PI = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow(int x, int y) {                                                             //return x^y in order(log(y))
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}
int A, B, X;
int calc(int mid) {
  return mid * A + B * (int)ceil(log10(mid)) <= X;
}

int bisect(int L, int R) {
  int mid = (L + R) / 2;
  if (mid == (int)1e9) return mid;
  if (mid == 1) return mid;
  if (calc(mid) and not calc(mid + 1)) {
    return mid;
  } else if (not calc(mid) and not calc(mid + 1)) {
    return bisect(L, mid);
  } else {
    return bisect(mid, R);
  }
}

class CBuyAnInteger {
public:
  static void solve(istream &cin, ostream &cout) {
    cin >> A >> B >> X;
    if (X < A + B) {
      cout << 0 << endl;
      return;
    }
    cout << bisect(1, (int)1e9 + 1) << endl;
  }
};


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  CBuyAnInteger solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
