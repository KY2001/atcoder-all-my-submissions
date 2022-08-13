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
#define SUM(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = (int)(1e9 + 7);
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int MOD1, MOD2;
int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm_plus(int a, int b) {                                                        //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD1; b; a = a * a % MOD1, b >>= 1)
    if (b & 1) res = res * a % MOD1;
  return res;
}
int bpm_minus(int a, int b) { //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD2; b; a = a * a % MOD2, b >>= 1)
    if (b & 1) res = res * a % MOD2;
  return res;
}

class DAnythingGoesToZero {
public:
  static void solve(istream &cin, ostream &cout) {
    int N;
    string X;
    cin >> N >> X;
    vector<int> process(200010, 0);
    REP(i, 1, 200001) {
      int temp = 0;
      rep(j, 20) if ((i >> j) & 1) temp++;
      process[i] = 1 + process[i % temp];
    }
    int zero, one;
    zero = 0;
    FOR(i, X)
    if (i == '0') zero++;
    one   = N - zero;
    int p = INF;
    if (one == 1) {
      rep(i, N) if (X[i] == '1') {
        p = i;
        break;
      }
    }
    int plus = 0, minus = 0;
    MOD1 = one + 1;
    MOD2 = max(one - 1, 1LL);
    rep(i, N) {
      if (X[i] == '1') {
        plus += bpm_plus(2, N - 1 - i);
        minus += bpm_minus(2, N - 1 - i);
        plus %= MOD1;
        minus %= MOD2;
      }
    }
    vector<int> ret(N);
    rep(i, N) {
      int ans = 0;
      if (X[i] == '1') {
        ans = minus;
        ans -= bpm_minus(2, N - 1 - i);
        ans = mod(ans, MOD2);
      } else {
        ans = plus;
        ans += bpm_plus(2, N - 1 - i);
        ans = mod(ans, MOD1);
      }
      if (i == p) {
        cout << 0 << endl;
      } else {
        cout << 1 + process[ans] << endl;
      }
    }
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  DAnythingGoesToZero solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
